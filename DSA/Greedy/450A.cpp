#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n ;
    int m;
    cin>>n>>m;
    queue<vector<int>>q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push({x,i});
    }
    while(q.size()>1){
        int req= q.front()[0]-m;
        if(req<=0){
            q.pop();
            continue;
        }
        int j  =q.front()[1];
        q.pop();
        q.push({req,j});

    }
    cout<<q.front()[1]+1;
    return 0;


}