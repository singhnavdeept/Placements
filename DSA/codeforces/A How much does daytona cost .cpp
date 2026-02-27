#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        int n ,k;
        cin>>n>>k;
        vector<int>v(n);
        bool flag=false;
        for(int i=0;i<n;i++){cin>>v[i];
            if (v[i]==k)flag=true;
        }

        if(flag){
        cout<<"YES"<<endl;}
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}