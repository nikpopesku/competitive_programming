#include <bits/stdc++.h>

using namespace std;

int furthest_node(int start, const vector<vector<int> > &adj, vector<int> *dist_out, const int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int best = 0;

    while (!q.empty()) {
        const auto node = q.front();
        q.pop();

        for (auto nei: adj[node]) {
            if (dist[nei] == -1) {
                dist[nei] = dist[node] + 1;
                best = max(best, dist[nei]);
                q.push(nei);
            }
        }
    }

    if (dist_out != nullptr) {
        *dist_out = std::move(dist);
    }

    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n;

    vector adj(n+1, vector<int>());
    for (int i = 1; i <= n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> a_dist(n + 1, -1), b_dist(n + 1, -1);
    const int a_end = furthest_node(1, adj, nullptr, n);
    const int b_end = furthest_node(a_end, adj, &a_dist, n);
    furthest_node(b_end, adj, &b_dist, n);

    for (int i = 1; i <= n; ++i) {
        cout << max(a_dist[i], b_dist[i]) << " ";
    }
}
