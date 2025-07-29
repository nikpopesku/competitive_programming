#include <iostream>
#include <map>
#include <ranges>

using namespace std;

constexpr int VERTICES = 200;
constexpr int EDGES = 1000;

void solve()
{
    int n, m, a, b;
    cin >> n >> m;
    int degree[VERTICES];
    map<int, int> mp;
    for (int& i : degree) i = 0;

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        ++degree[a];
        ++degree[b];
    }

    int leaves = 0;

    for (int i : degree)
    {
        if (i == 1)
        {
            ++leaves;
        }
        else if (i > 1)
        {
            ++mp[i];
        }
    }

    if (mp.size() == 2)
    {
        for (auto [fst, snd] : mp)
        {
            if (snd == 1)
            {
                cout << fst << " " << leaves / fst << "\n";
                return;
            }
        }
    }
    else
    {
        for (const auto snd : mp | views::values)
        {
            cout << snd - 1 << " " << leaves / (snd - 1) << "\n";
            return;
        }
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
