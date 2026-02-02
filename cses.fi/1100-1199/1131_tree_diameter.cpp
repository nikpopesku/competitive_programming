#include<bits/stdc++.h>

using namespace std;

int calc(int node, unordered_map<int, vector<int> > adj, int &maxdiameter) {
    int first = 0;
    if (adj[node].size() > 0) {
        first = calc(adj[node][0], adj, maxdiameter) + 1;
    }

    int second = 0;
    if (adj[node].size() > 1) {
        second = calc(adj[node][1], adj, maxdiameter) + 1;
    }

    maxdiameter = max(maxdiameter, first + second);

    return first + second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, u, v;
    cin >> n;
    unordered_map<int, vector<int> > adj;

    for (int i = 1; i <= n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxdiameter = 0;
    calc(1, adj, maxdiameter);
    cout << maxdiameter << "\n";
}
