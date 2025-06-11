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

    const int k = n / 2;
    int response = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            const int sz = vc[i][j] + vc[n - i - 1][j] + vc[n - i - 1][n - j - 1] + vc[i][n - j - 1];

            if (sz == 1 or sz == 3)
            {
                response += 1;
            }
            else if (sz == 2)
            {
                response += 2;
            }
        }
    }

    if (n % 2 == 1)
    {
        for (int i = 0; i < k; ++i)
        {
            const int sz = vc[k][i] + vc[k][n - i - 1] + vc[i][k] + vc[n - i - 1][k];

            if (sz == 1 or sz == 3)
            {
                response += 1;
            }
            else if (sz == 2)
            {
                response += 2;
            }
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
