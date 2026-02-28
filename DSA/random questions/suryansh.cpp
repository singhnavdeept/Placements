#include <bits/stdc++.h>
using namespace std;
int uglyfinder(vector<int>& arr,int maxx) {
    int ans;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == maxx) ans++; 
    }
    return ans;
}
int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int length;
        cin >> length;
        vector<int> arr(length,0);
        for (int i  = 0; i < length; i++) {
            cin >> arr[i]; 
        }
        int maxx = *max_element(arr.begin(), arr.end());
    }
}