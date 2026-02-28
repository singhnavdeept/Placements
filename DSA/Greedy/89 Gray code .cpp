#include<bits/stdc++.h>
using namespace std;
int n=10;



void solve(){
    
    for(int i=0;i<pow(2,n);i++){
        cout<<(i^(i>>1))<<" ";
        
    }

}
int main(){
    
    solve();
    
    return 0;
}