#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


const int MAXN = 200005;
const int LOGN = 18; 

vector<int> adj[MAXN]; 
int depth[MAXN];      
int up[MAXN][LOGN];
void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p; 
    for (int v : adj[u]) {
           dfs(v, u, d + 1);
    }
}
int get_lca(int u, int v) {
      if (depth[u] < depth[v]) {
        swap(u, v);
    }
  int diff = depth[u] - depth[v];
    for (int j = LOGN - 1; j >= 0; --j) {
        if ((diff >> j) & 1) {
            u = up[u][j];
        }
    }
 if (u == v) {
        return u;
    }
    for (int j = LOGN - 1; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    
    for (int i = 2; i <= n; ++i) {
        int mg;
        cin >> mg;
        adj[mg].push_back(i);
    }
    dfs(1, 1, 0); 
    for (int j = 1; j < LOGN; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << get_lca(u, v) << "\n";
    }
     return 0;
}