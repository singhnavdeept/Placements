#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n =s.size();
    vector<int>v;
    for(int i=0;i<n;i++){
        if(s[i]=='-'){
            if(i<n && s[i+1]=='.'){
                v.push_back(1);
                i++;
            }
            else if(i<n && s[i+1]=='-'){
                v.push_back(2);
                i++;
            }
        }
        else if(s[i]=='.'){
            v.push_back(0);
        }

    }
    for(int i :v){
        cout<<i;
    }
    return 0;
}