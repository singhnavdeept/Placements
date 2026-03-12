#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long x=0;
    for(int i=1;i<=n;i++){
        x+=__builtin_popcount(i);
    }
    cout<<x<<"\n";
    return 0;
    
}