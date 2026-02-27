#include <iostream>
#include <vector>

using namespace std;

// --- Data Structures ---
// It's fine to keep these global for convenience,
// as long as we remember to clear them.
const int MAXN = 100005; 
vector<int> adj[MAXN];

// --- DFS Helper ---
// Takes a reference to a 'visited' vector that belongs to a specific test case.
void dfs(int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, visited);
        }
    }
}

// --- Main Logic ---
void solve() {
    int n, m;
    cin >> n >> m;
    
    // --- STEP 1: RESET GLOBAL STATE ---
    // For each new test case, clear the adjacency list from the previous run.
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // --- STEP 2: USE LOCAL STATE FOR 'visited' ---
    // This vector is created fresh every time solve() is called.
    // No need to manually reset it.
    vector<bool> visited(n + 1, false);

    vector<int> representatives;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            representatives.push_back(i);
            dfs(i, visited);
        }
    }
    
    int roads_needed = representatives.size() > 0 ? representatives.size() - 1 : 0;
    
    cout << roads_needed << endl;

    for (int i = 0; i < roads_needed; ++i) {
        cout << representatives[i] << " " << representatives[i + 1] << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Some problems have a 't' for number of test cases.
    // CSES problems often don't, but wrapping logic in a `solve()`
    // function is a great habit for being ready for those that do.
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    solve(); // For CSES, just call solve() once.

    return 0;
}