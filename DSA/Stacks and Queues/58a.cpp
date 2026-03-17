#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin>>s;
    string h="hello";
    int j=0;
    int flag=false;
    for(int i=0;i<s.size();i++){
        if(s[i]==h[j]){
            j++;
            if(j==h.size()){
                
                flag=true;
                break;
            }
        }
    }
    
    if(flag)cout<<"YES";
    else cout<<"NO";
    return 0;
}

class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        int ml = 2;

        auto diff = [&](int d) {
            int currm = 0;
            int count = 0;
            int skips = 0;
            int lastskip = -1;
            int startIdx = 0;

            for (int i = 0; i < n; i++) {
                
                long long expected = (long long)nums[startIdx] + (long long)(i - startIdx) * d;
                
                if (nums[i] == expected) {
                    count++;
                } else if (skips == 0) {
                    skips = 1;
                    lastskip = i;
                    count++;
                } else {
                    currm = max(currm, count);
                     i = lastskip;
                    startIdx = i;
                    count = 1;
                    skips = 0;
                }
                currm = max(currm, count);
            }
            return currm;
        };

        // We only need to check differences created by the first 3 elements
        // of any potential arithmetic subarray.
        for (int i = 0; i < n - 1; i++) {
            // Case 1: The difference is determined by nums[i] and nums[i+1]
            ml = max(ml, diff(nums[i + 1] - nums[i]));
            
            // Case 2: The difference is determined by nums[i] and nums[i+2]
            // where nums[i+1] is the element we might change.
            if (i + 2 < n) {
                int d2 = nums[i + 2] - nums[i];
                if (d2 % 2 == 0) {
                    ml = max(ml, diff(d2 / 2));
                }
            }
        }
        return ml;
    }
};