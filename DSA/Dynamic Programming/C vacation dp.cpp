#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<int>a,b,c;
vector<vector<int>>dp;
int n;
int rec(int day , int flag){
    if(day==n){
        return 0;
    }
    if(dp[day][flag]!=0)return dp[day][flag];
    int happiness=0;
    int happiness2=0;
    int happiness3=0;
    if(flag!=1){
        happiness= a[day]+rec(day+1,1);
    }
    if(flag!=2){
        happiness2=b[day]+rec(day+1,2);
    }
    if(flag!=3){
        happiness3=c[day]+rec(day+1,3);
    }
    return dp[day][flag]=max({happiness2,happiness3,happiness});
}
int main(){
     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   
    cin>>n;
    a.resize(n);b.resize(n);c.resize(n);
    for(int i =0;i<n;i++){
        cin>>a[i];cin>>b[i];cin>>c[i];
       
        
    }
    dp.resize(n,vector<int>(4,0));

    cout<<rec(0,0)<<endl;
    return 0;

}