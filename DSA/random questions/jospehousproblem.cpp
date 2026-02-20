#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1;i<n+1;i++){
        q.push(i);
    }
    while(!q.empty()){
        int x= q.front();
        q.pop();
        q.push(x);
        int y= q.front();
        q.pop();
        
        cout<<y<<" ";
    }
    return 0;
}