#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define ll long long

ll dfs(set<pair<ll, ll>>& visited, vector<vector<ll>>& v, const ll& n, const ll& m, vector<pair<ll, ll>>& stack)
{
    ll response = 0;

    vector<pair<ll, ll>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!stack.empty())
    {
        auto [i, j] = stack.back();
        stack.pop_back();
        if (visited.contains({i, j})) continue;

        visited.insert({i, j});
        response += v[i][j];

        for (auto [x, y]: directions)
        {
            ll new_x = i + x;
            ll new_y = j + y;

            if (new_x >= 0 and new_x < n and new_y >= 0 and new_y < m and !visited.contains({new_x, new_y}) and v[new_x][
                new_y] > 0)
            {
                stack.emplace_back(new_x, new_y);
            }
        }
    }

    return response;
};

void solve()
{
    ll n, m, max_value = 0;
    cin >> n >> m;
    vector v(n, vector(m, 0LL));
    set<pair<ll, ll>> visited;


    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
    }

    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            if (v[i][j] > 0 && !visited.contains({i, j}))
            {
                vector<pair<ll, ll>> stack = {{i, j}};
                max_value = max(max_value, dfs(visited, v, n, m, stack));
            }
        }
    }

    cout << max_value << "\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
