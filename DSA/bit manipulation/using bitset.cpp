#include<bitset>
#include<iostream>
using namespace std;
int main(){
    int n=5;
    bitset<32>b(n);
    for(int i=0;i<b.size();i++){
        cout<<b[i];
    }
    b.flip();
    cout<<"\n";
    for(int i=0;i<b.size();i++){
        cout<<b[i];
    }
    return 0;

    //0000000000
    //1010000000

}