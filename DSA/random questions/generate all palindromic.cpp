#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include<iostream>

using namespace std;

// Check if the given string is a palindrome
bool isPalindrome(string& s) {
    
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i++] != s[j--]) 
            return false;
    }
    return true;
}

// Recursive function to find all palindromic partitions
void backtrack(int idx, string& s, vector<string>& curr,
    vector<vector<string>>& res) {
    
    for(auto c:curr){
        cout<<c;

    }
    cout<<endl;
    if (idx == s.size()) {
        // Store valid partition
        res.push_back(curr); 
        return;
    }
    
    string temp = "";
    for (int i = idx; i < s.size(); ++i) {
        
        cout<<temp<<endl;
        if (isPalindrome(temp)) {
            // Choose the substring
            curr.push_back(temp);            
            // Explore further

            backtrack(i + 1, s, curr, res);  
            // Backtrack
            curr.pop_back();                 
        }
    }
}

// Return all palindromic partitions of string s
vector<vector<string>> palinParts(string& s) {
    vector<vector<string>> res;
    vector<string> curr;
    backtrack(0, s, curr, res);
    return res;
}


int main() {
    string s = "geeks";

    vector<vector<string>> res = palinParts(s);

    // Print result: one partition per line
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j];
            if (j != res[i].size() - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}