#include<iostream>
#include<string>
using namespace std;
int main(){
    string n;
    cin>>n;
    int lucky=0;
    for(char c:n){
        if(c=='4' ||c=='7'){
            lucky++;
        }
    }
    if(lucky==4 || lucky==7){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}