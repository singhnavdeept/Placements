#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    
    int s ;
    int n ;
    cin>>s>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    int i;
    bool flag= true;
    for( i =0;i<n;i++){
        if(v[i].first<s){
            s+=v[i].second;
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag)cout<<"YES";
    else cout<<"NO";
    return 0;
}