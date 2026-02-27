#include <bits/stdc++.h>
using namespace std;
    
    int dfs(int b , const vector<vector<int>>& adj,const vector<int>& v){
        int count=0;
        for(int s:adj[b]){
            count= max(count , dfs(s,adj,v));
        }
        return v[b]+count;
    }
    int solve(int a, int b, vector<int>& v1, vector<int>& v2) {
        vector<vector<int>>adj(a);
        
        for(int i=0;i<a;i++){
            if(v1[i]==-1)continue;
            adj[v1[i]].push_back(i);
            
        }
        
        return dfs(b,adj, v2);
        


    }


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int n;
    
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];

    // input size of second vector
   
    vector<int> v2(n);
    for (int i = 0; i < n; i++)
        cin >> v2[i];


    int result = solve(a, b, v1, v2);

    cout << result << "\n";

    return 0;
}