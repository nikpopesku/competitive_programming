#include <bits/stdc++.h>

using namespace std;

template <class T>
bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template <typename T>
ostream& operator<<(ostream& out, vector<T>& a)
{
    for (auto& x : a) out << x << ' ';
    return out;
}

void solve()
{
    int n, max_k = 0;
    cin >> n;
    vector<vector<int>> numbers(n), g;

    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        max_k = max(max_k, k);

        for (int j = 0; j < k; ++j)
        {
            cin >> numbers[i][j];
            if (g[j].size() == j)
            {
                g[j].emplace_back();
            }
            g[j].push_back(i);
        }
    }

    vector<int> lex_min, rank(n, -1);

    for (int i = max_k - 1; i >= 0; --i)
    {
        vector<array<int, 3>> cur;

        for (const auto& j : g[i])
        {
            cur.push_back({numbers[j][i], rank[i], j});
        }

        sort(cur.begin(), cur.end());
        lex_min[i] = cur[0][2];
        int rk = 0;
        for (auto& c : cur)
        {
            rank[c[2]] = rk++;
        }
    }

    vector<int> ans;
    while (static_cast<int>(ans.size()) < max_k)
    {
        const int tmp = static_cast<int>(ans.size());

        for (int i = tmp; i < static_cast<int>(numbers[lex_min[tmp]].size()); ++i)
        {
            ans[i] = numbers[lex_min[tmp]][i];
        }
    }

    cout << ans << "\n";
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        solve();
    }
}
