#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Change return type and parameters as needed
    int solve(int a, int b, vector<int>& v1, vector<int>& v2) {
        
        // Your logic here
        int sum = a + b;

        for (int x : v1) sum += x;
        for (int x : v2) sum += x;

        return sum;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int n, m;
    
    // input size of first vector
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];

    // input size of second vector
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    Solution obj;

    int result = obj.solve(a, b, v1, v2);

    cout << result << "\n";

    return 0;
}