#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n;
    cin>>n>>t;
    vector<vector<int>>adj(n+1);
    vector<int>indegree(n+1);
    indegree[0]=INT_MAX;
    for(int i=0;i<t;i++){
        int a;int b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int>q;
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>res;
    while(!q.empty()){
        int curr = q.front();
        res.push_back(curr);
        q.pop();
        for(int i:adj[curr]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    if(res.size()==n){
        for(int i:res){
            cout<<i<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
    

}