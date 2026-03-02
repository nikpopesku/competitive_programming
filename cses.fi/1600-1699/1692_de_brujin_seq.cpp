#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>& result, int node, vector<vector<int>>& adj) {
    while (!adj[node].empty()) {
        const int nei = adj[node].back();
        adj[node].pop_back();
        dfs(result, nei, adj);
    }

    result.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    const int mx = pow(2, n-1);
    vector adj(mx, vector<int>());

    for (int i = 0; i < mx; ++i) {
        adj[i].push_back((i * 2 + 0) % mx);
        adj[i].push_back((i * 2 + 1) % mx);
    }

}
