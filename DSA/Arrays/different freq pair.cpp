#include <vector>
#include <map>
using namespace std;
vector<int> findPair(vector<int>& nums) {
  
    map<int, int> mp;
    for (int num : nums) {
        mp[num]++;
    }
    for (auto p1 = mp.begin(); p1 != mp.end(); ++p1) {
        int x = p1->first;
        int freq_x = p1->second;
        auto p2 = p1;
        ++p2; 
        for (; p2 != mp.end(); ++p2) {
            int y = p2->first;
            int freq_y = p2->second;
            if (freq_x != freq_y) {
                return {x, y};
            }
        }
    }
    return {-1, -1};
}