#include<bits/stdc++.h>

using namespace std;

int calc(int node, int parent, vector<int> &distance, vector<vector<int> > &adj) {
    int best1 = 0;
    int best2 = 0;

    for (auto nei: adj[node]) {
        if (nei == parent) {
            continue;
        }

        int dist = calc(nei, node, distance, adj) + 1;
        distance[node] = max(distance[node], dist);

        if (dist > best1) {
            best2 = best1;
            best1 = dist;
        } else if (dist > best2) {
            best2 = dist;
        }
    }
 return best1 + best2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n;

    vector<vector<int> > adj;
    vector<int> distance(n, 0);

    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calc(1, 0, distance, adj);

    for (int i = 0; i < n; ++i) {
        cout << distance[i] << ' ';
    }

    cout << "1\n";
}
