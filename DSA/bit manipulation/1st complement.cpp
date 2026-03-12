#include<bitset>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
    int n =0;
    cin>>n;
    int mask=0;
    int temp =n;
    while(temp>0){
        mask = mask<<1 |1;
        temp = temp>>1;
    }
    int x= n==0?1:n^mask;
    cout<<x;
    return 0;
    
}