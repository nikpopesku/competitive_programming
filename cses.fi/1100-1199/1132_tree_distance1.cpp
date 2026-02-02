#include <bits/stdc++.h>

using namespace std;

static int bfs_farthest(int start, const vector<vector<int>> &adj, vector<int> *dist_out) {
    int n = static_cast<int>(adj.size()) - 1;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int nei : adj[node]) {
            if (dist[nei] != -1) {
                continue;
            }
            dist[nei] = dist[node] + 1;
            q.push(nei);
        }
    }

    int best_node = start;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > dist[best_node]) {
            best_node = i;
        }
    }
    if (dist_out != nullptr) {
        *dist_out = std::move(dist);
    }
    return best_node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist_a, dist_b;
    int a_end = bfs_farthest(1, adj, nullptr);
    int b_end = bfs_farthest(a_end, adj, &dist_a);
    bfs_farthest(b_end, adj, &dist_b);

    for (int i = 1; i <= n; ++i) {
        cout << max(dist_a[i], dist_b[i]) << (i == n ? '\n' : ' ');
    }
}
