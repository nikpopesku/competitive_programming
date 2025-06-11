#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector vc(n, vector<int>(n));
    string s;

    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < n; ++j)
        {
            vc[i][j] = s[j] == '1' ? 1 : 0;
        }
    }

    int response = 0;
    for (int i = 0; i < (n + 1) / 2; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            const int sz = vc[i][j] + vc[j][n - i - 1] + vc[n - i - 1][n - j - 1] + vc[n - j - 1][i];
            response += min(sz, 4 - sz);
        }
    }

    cout << response << "\n";
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
