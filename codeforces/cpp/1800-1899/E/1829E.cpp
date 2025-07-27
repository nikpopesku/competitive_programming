#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dfs(int i, int j, set<pair<int, int>>& visited, vector<vector<int>>& v, int& n, int& m)
{
    visited.insert({i, j});
    int response = v[i][j];

    for (auto [x, y] : {{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    {
        int new_x = i + x;
        int new_y = j + y;

        if (new_x >= 0 and new_x < n and new_y >= 0 and new_y < m and !visited.contains(new_x, new_y) and v[new_x][
            new_y] > 0)
        {
            response += dfs(new_x, new_y, visited, v, n, m);
        }
    }

    return response;
};

void solve()
{
    int n, m, max_value = 0;
    cin >> n >> m;
    vector v(n, vector(m, 0));
    set<pair<int, int>> visited;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (v[i][j] > 0 && !visited.contains({i, j}))
            {
                max_value = max(max_value, dfs(i, j, visited, v, n, m));
            }
        }
    }

    cout << max_value <<"\n";
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
