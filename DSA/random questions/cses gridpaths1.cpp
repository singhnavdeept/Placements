#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n,'*'));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c;
            cin >>c;
            grid[i][j]=c;
        }}
    vector<vector<int>> dp(n, vector<int>(n, 0));

    if (grid[0][0] == '*') {
        cout << 0;
        return 0;
    }

    dp[0][0] = 1;
    int maxdp=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }

            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) ;
                maxdp=max(maxdp,dp[i][j]);

            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) ;
                 maxdp=max(maxdp,dp[i][j]);
        }
    }

    cout << maxdp;
}
