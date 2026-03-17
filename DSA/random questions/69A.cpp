#include<vector>
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n =0;
    cin>>n;
    int fx=0;
    int fy=0;
    int fz=0;
    int x,y,z;
    while(n--){
        
        cin>>x>>y>>z;
        fx+=x;
        fy+=y;
        fz+=z;
    }
    if(fx==0 && fz==0 && fy==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}