#include <iostream>
#include <vector>

using namespace std;

const int MAXA = 1000005;
bool seen[MAXA];
bool U[MAXA];

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> b(n);
     for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> a(l);
        for (int j = 0; j < l; j++) {
            cin >> a[j];
        }
        vector<int> cur_b;
        for (int j = l - 1; j >= 0; j--) {
            if (!seen[a[j]]) {
                seen[a[j]] = true;
                cur_b.push_back(a[j]);
            }
        }
        for (int x : cur_b) {
            seen[x] = false;
        }
        b[i] = cur_b;
    }
    vector<int> used_elements;
    vector<bool> posted(n, false);
    vector<int> Q;
    auto is_less = [&](int idx1, int idx2) {
        int p1 = 0, p2 = 0;
        while (true) {
              while (p1 < b[idx1].size() && U[b[idx1][p1]]) p1++;
            while (p2 < b[idx2].size() && U[b[idx2][p2]]) p2++;
            
            bool end1 = (p1 == b[idx1].size());
            bool end2 = (p2 == b[idx2].size());
            
            if (end1 && end2) return false;     
            if (end1) return true;              
            if (end2) return false;             
            
            if (b[idx1][p1] != b[idx2][p2]) {
                return b[idx1][p1] < b[idx2][p2];
            }
            
            p1++;
            p2++;
        }
    };
    for (int step = 0; step < n; step++) {
        int best_idx = -1;
          for (int i = 0; i < n; i++) {
            if (posted[i]) continue;
            
            if (best_idx == -1) {
                best_idx = i;
            } else {
                if (is_less(i, best_idx)) {
                    best_idx = i;
                }
            }
        }
        
        posted[best_idx] = true;
        for (int x : b[best_idx]) {
            if (!U[x]) {
                Q.push_back(x);
                U[x] = true;
                used_elements.push_back(x);
            }
        }
    }
       for (int i = 0; i < (int)Q.size(); i++) {
        cout << Q[i] << (i + 1 == (int)Q.size() ? "" : " ");
    }
    cout << "\n";
       for (int x : used_elements) {
        U[x] = false;
    }
}

int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}