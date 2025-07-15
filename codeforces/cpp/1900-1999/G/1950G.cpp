#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> genres(n);
    vector<string> writers(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> genres[i] >> writers[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    vector adj(n, vector(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j and (genres[i] == genres[j] || writers[i] == writers[j]))
            {
                adj[i][j] = 1;
            }
        }
    }

    vector dp(1 << n, vector(n, 0));
    for (int i = 0; i < n; ++i)
    {
        dp[1 << i][i] = 1;
    }

    int max_len = 1;
    for (int mask = 1; mask < 1 << n; ++mask)
    {
        for (int i = 0; i < n; ++i)
        {
            if (dp[mask][i] > 0)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (!(mask & (1 << j)) && adj[i][j])
                    {
                        const int next_mask = mask | (1 << j);
                        dp[next_mask][j] = max(dp[next_mask][j], dp[mask][i] + 1);
                        max_len = max(max_len, dp[next_mask][j]);
                    }
                }
            }
        }
    }

    cout << n - max_len << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
