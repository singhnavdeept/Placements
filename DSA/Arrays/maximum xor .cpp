#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string maximumXor(string s, string t) {

        int n = s.size();

        int count0 = 0, count1 = 0;

        for(char c : t)
        {
            if(c == '0') count0++;
            else count1++;
        }

        string result = "";

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(count1 > 0)
                {
                    result.push_back('1');
                    count1--;
                }
                else
                {
                    result.push_back('0');
                    count0--;
                }
            }
            else
            {
                if(count0 > 0)
                {
                    result.push_back('1');
                    count0--;
                }
                else
                {
                    result.push_back('0');
                    count1--;
                }
            }
        }

        return result;
    }
};