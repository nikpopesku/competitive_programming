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
    int n;
    cin >> n;
    vector<vector<int>> g(n), relevant;
    int max_k = 0;

    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        g[i].resize(k);
        ckmax(max_k, k);

        for (int j = 0; j < k; ++j)
        {
            cin >> g[i][j];
            if (static_cast<int>(relevant.size()) == j) relevant.emplace_back();
            relevant[j].push_back(i);
        }
    }

    vector<int> lex_min(max_k), rank(n, -1);

    for (int i = max_k - 1; i >= 0; --i)
    {
        vector<array<int, 3>> cur;
        for (const auto& j : relevant[i])
        {
            cur.push_back({g[j][i], rank[j], j});
        }
        sort(cur.begin(), cur.end());
        lex_min[i] = cur[0][2];
        int rk = 0;
        for (auto& j : cur) rank[j[2]] = rk++;
    }

    vector<int> ans;

    while (static_cast<int>(ans.size()) < max_k)
    {
        const int tmp = static_cast<int>(ans.size());
        auto& v = g[lex_min[tmp]];
        for (int i = tmp; i < static_cast<int>(v.size()); ++i) ans.push_back(v[i]);
    }

    assert(static_cast<int>(ans.size()) == max_k);
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
