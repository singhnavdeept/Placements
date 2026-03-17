#include<cctype>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cup=0;
    int cdown=0;
    for(char c:s){
        if(islower(c)){
            cdown++;
        }
        else{
            cup++;
        }
    }
    if(cdown>=cup){
       for(auto &c:s){
        c=tolower(c);
       }
    }
    else{
        for(auto &c:s){
            c=toupper(c);
        }
    }
    cout<<s;
    return 0;

}