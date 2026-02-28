#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeString(string s, int k) {
        bool flag = true;
        
        while (flag) {
            flag = false;
            int n = s.length();
            
            for (int i = 0; i < n; ++i) {
                  for (int j = i + 1; j < n && (j - i) <= k; ++j) {
                    if (s[i] == s[j]) {
                        s.erase(j, 1);
                        flag = true;
                        break; 
                    }
                }
                if (flag) break;
        }
        
        return s;
    }
};