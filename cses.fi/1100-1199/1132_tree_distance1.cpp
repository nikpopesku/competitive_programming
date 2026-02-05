#include <bits/stdc++.h>

using namespace std;

int furthest_node(int start, vector<vector<int> > &adj, vector<int> *dist) {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n;

    vector adj(n, vector<int>());
    for (int i = 1; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int a_end, b_end;
    vector<int> a_dist, b_dist;
    a_end = furthest_node(1, adj, nullptr);
    b_end = furthest_node(a_end, adj, &a_dist);
    furthest_node(b_end, adj, &b_dist);

    for (int i = 1; i <= n; ++i) {
        cout << max(a_dist[i], b_dist[i]) << " ";
    }
}
