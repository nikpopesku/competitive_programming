#include <iostream>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int u = -1, v = -1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (u == -1)
        {
            u = i;
            continue;
        }

        if (s[u] != s[i])
        {
            v = i;
            break;
        }
    }

    if (u == -1 || v == -1)
    {
        cout << "NO\n";
    }
    else
    {
        swap(s[u], s[v]);
        cout << "YES\n";
        cout << s << "\n";
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
