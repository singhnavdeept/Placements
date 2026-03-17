#include<iostream>
#include<vector>
using namespace std;
bool check(int s){
    vector<int>v;
    while(s!=0){
        v.push_back(s%10);
        s=s/10;

    }
    for(int i =0;i<v.size();i++){
        for(int j =i+1;j<v.size();j++){
            if(v[i]==v[j]){
               return false;
            }
        }
    }
    return true;
}
int main(){
    int start;
    cin>>start;
    ++start;
    while(!check(start)){
        start++;
    }
    cout<<start;
    return 0;

}