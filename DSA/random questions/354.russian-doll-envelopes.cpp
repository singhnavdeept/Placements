/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // Sort width ascending, height descending if equal width
        sort(envelopes.begin(), envelopes.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });

        vector<int> temp;

        for (auto &env : envelopes) {
            int h = env[1];

            auto it = lower_bound(temp.begin(), temp.end(), h);

            if (it == temp.end()) {
                temp.push_back(h);
            } else {
                *it = h;
            }
        }

        return temp.size();
    }
};

// @lc code=end

