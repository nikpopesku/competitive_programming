#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, value;
    cin >> n;
    vector<vector<int>> adj_list(n+1);
    string s;

    for (int i = 2; i <= n; ++i)
    {
        cin >> value;
        adj_list[value].push_back(i);
        adj_list[i].push_back(value);
    }

    cin >> s;
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
