class Solution {
public:
    bool dfs(vector<vector<int>>&adj, vector<int>& color,int c , int curr){
        color[curr]=c;
        for(int i:adj[curr]){
            if(color[i]==-1){
                if(!dfs(adj, color, 1-c,i)){
                    return false;
                }
            }
            else if(color[i]==c){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(graph, color, 0,i)){
                    return false;
                }
            }
        }
        return true;
    }
};