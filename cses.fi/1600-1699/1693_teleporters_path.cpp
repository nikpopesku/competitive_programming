#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;
    vector adj(n+1, vector<int>());
    vector<int> indegree (n+1, 0);
    vector<int> outdegree (n+1, 0);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        ++outdegree[a];
        ++indegree[a];
    }

    vector<int> response;
    ranges::reverse(response);

    if (response[0] != 1 || response.back() != n) {
        cout << "IMPOSSIBLE\n";
    }

    if (static_cast<int>(response.size()) != m + 1) {
        cout << "IMPOSSIBLE\n";
    }

    for (auto &i: response) {
       cout << i << ' ';
    }
}
