#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;
    vector adj(n + 1, vector<int>());

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> result;
    ranges::reverse(result);

    for (const auto &i: result) {
        cout << i << ' ';
    }
}
