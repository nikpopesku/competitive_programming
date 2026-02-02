#include<bits/stdc++.h>

using namespace std;

int calc(int node, int parent, unordered_map<int, vector<int> > &adj, int &maxdiameter) {
    int best1 = 0;
    int best2 = 0;

    for (const auto nei: adj[node]) {
        if (nei == parent) {
            continue;
        }

        int diameter = calc(nei, node, adj, maxdiameter) + 1;
        if (diameter > best1) {
            best2 = best1;
            best1 = diameter;
        } else if (diameter > best2) {
            best2 = diameter;
        }

        maxdiameter = max(maxdiameter, best1 + best2);
    }

    return best1;
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
    calc(1, 0, adj, maxdiameter);
    cout << maxdiameter << "\n";
}
