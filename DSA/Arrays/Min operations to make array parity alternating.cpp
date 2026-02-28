#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    long long getMinRange(const vector<long long>& nums, const vector<int>& targetParity) {
        int n = nums.size();
        vector<pair<long long, int>> candidates;
        
        for (int i = 0; i < n; ++i) {
            if (abs(nums[i] % 2) == targetParity[i]) {
                candidates.push_back({nums[i], i});
            } else {
                candidates.push_back({nums[i] - 1, i});
                candidates.push_back({nums[i] + 1, i});
            }
        }
        
        sort(candidates.begin(), candidates.end());
        
        long long minRange = LLONG_MAX;
        vector<int> count(n, 0);
        int uniqueIndices = 0;
        int left = 0;
        
        for (int right = 0; right < candidates.size(); ++right) {
            if (count[candidates[right].second]++ == 0) uniqueIndices++;
            
            while (uniqueIndices == n) {
                minRange = min(minRange, candidates[right].first - candidates[left].first);
                if (--count[candidates[left].second] == 0) uniqueIndices--;
                left++;
            }
        }
        return minRange;
    }

    vector<long long> solve(vector<int>& nums_int) {
        int n = nums_int.size();
        if (n == 1) return {0, 0};
        
        vector<long long> nums;
        for(int x : nums_int) nums.push_back(x);

        vector<int> patternA(n), patternB(n);
        int costA = 0, costB = 0;
        
        for (int i = 0; i < n; ++i) {
            patternA[i] = i % 2;       
            patternB[i] = (i + 1) % 2; 
            if (abs(nums[i] % 2) != patternA[i]) costA++;
            if (abs(nums[i] % 2) != patternB[i]) costB++;
        }

        if (costA < costB) {
            return {(long long)costA, getMinRange(nums, patternA)};
        } else if (costB < costA) {
            return {(long long)costB, getMinRange(nums, patternB)};
        } else {
            return {(long long)costA, min(getMinRange(nums, patternA), getMinRange(nums, patternB))};
        }
    }
};