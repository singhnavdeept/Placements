#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        int ts = 0;
        bool res = false;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != s[(i + 1) % n])
                ts++;
            else
                res = true;
        }

        if (res)
            cout << ts + 1 << "\n";
        else
            cout << ts << "\n";
    }
}