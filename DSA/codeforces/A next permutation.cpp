#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int count_ugly(const vector<int>& q) {
    int count = 0;
    int current_max = 0;
    for (int i = 0; i < q.size(); ++i) {
        if (q[i] > current_max) {
            count++;
            current_max = q[i];
        }
    }
    return count;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
   vector<int> best_q = p;
    int min_ugly = count_ugly(p);
   for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> temp_p = p;
            swap(temp_p[i], temp_p[j]);
            int current_ugly = count_ugly(temp_p);
            
            if (current_ugly < min_ugly) {
                min_ugly = current_ugly;
                best_q = temp_p;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << best_q[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}