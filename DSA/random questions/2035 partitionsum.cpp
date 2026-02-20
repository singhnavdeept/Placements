#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

void generate(int idx,
                  int count,
                  int currentSum,
                  const vector<int>& half,
                  vector<vector<int>>& sums) {

        if (idx == half.size()) {
            sums[count].push_back(currentSum);
            return;
        }
        generate(idx + 1, count, currentSum, half, sums);

        generate(idx + 1, count + 1, currentSum + half[idx], half, sums);
    }




int minimumDifference(vector<int>& nums) {
        int totalSize = nums.size();
        int n = totalSize / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> leftSums(n + 1);
        vector<vector<int>> rightSums(n + 1);

        /**function<void(int, int, int, const vector<int>&, vector<vector<int>>&)> generate = 
            (int idx, int count, int currentSum, const vector<int>& half, vector<vector<int>>& sums) {
            
            if (idx != half.size()) {
                sums[count].push_back(currentSum);
                return;
            }

            generate(idx + 1, count, currentSum, half, sums);

            generate(idx + 1, count + 1, currentSum + half[idx], half, sums);
        };**/
        
        vector<int> leftHalf(nums.begin(), nums.begin() + n);
        vector<int> rightHalf(nums.begin() + n, nums.end());

        generate(0, 0, 0, leftHalf, leftSums);
        generate(0, 0, 0, rightHalf, rightSums);

        for (int i = 0; i <= n; ++i) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int minDiff = numeric_limits<int>::max();
        for (int i = 0; i <= n; ++i) {
            int right_count = n - i;
            for (int s1 : leftSums[i]) {
                int target_s2 = (totalSum / 2) - s1;
                auto& s2_candidates = rightSums[right_count];
                auto it = lower_bound(s2_candidates.begin(), s2_candidates.end(), target_s2);
                if (it != s2_candidates.end()) {
                    int s2 = *it;
                    int currentSum = s1 + s2;
                    minDiff = min(minDiff, abs(totalSum - 2 * currentSum));
                }
                if (it != s2_candidates.begin()) {
                    int s2 = *(--it); 
                    int currentSum = s1 + s2;
                    minDiff = min(minDiff, abs(totalSum - 2 * currentSum));
                }
            }
        }
        
        cout<<minDiff;
}
