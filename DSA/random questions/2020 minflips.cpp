#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int n, int x) {
        vector<int>s;
        while(n>0){
            s.push_back(n%2);
            n=n/2;
        }
        vector<int>y;
        while(x>0){
            y.push_back(x%2);
            x=x/2;
        }
        
        for(int i:s){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i:y){
            cout<<i<<" ";
        }
        
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int x;
    cin >>x;

    

    Solution obj;
    cout << obj.solve(n, x) << "\n";

    return 0;
}
