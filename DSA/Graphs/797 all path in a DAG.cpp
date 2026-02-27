/*
USIGN SIMPLE DFS APPROACH
class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<vector<int>>& adj,int curr,vector<int>&ans){
        if(curr==adj.size()-1){
            res.push_back(ans);
            return;}
        if(adj[curr].empty() && curr==adj.size()-1){
            res.push_back(ans);
            return;
        }
        
        for(int n:adj[curr]){
            ans.push_back(n);
            dfs(adj,n,ans);
            ans.pop_back();
        }
        return;
    
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>ans;
        ans.push_back(0);
        dfs(graph,0,ans);
        return res;
    }
};*/