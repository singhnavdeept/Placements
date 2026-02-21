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

        vector<int> p, v;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                p.push_back(i + 1);
            else
                v.push_back(i + 1);
        }

        if (p.size() % 2 == 0)
        {
            cout << p.size() << "\n";
            for (int x : p)
                cout << x << " ";
            cout << "\n";
        }
     
        else if (v.size() % 2 == 1)
        {
            cout << v.size() << "\n";
            for (int x : v)
                cout << x << " ";
            cout << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}