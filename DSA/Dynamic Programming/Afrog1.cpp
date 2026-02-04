#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;i++){cin>>v[i];}
   
    vector<int>dp(n,0);
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    for(int i =2;i<v.size();i++){
        dp[i] =  min( dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i]-v[i-2]));
    }
    cout<<dp[n-1];
    return 0;

}