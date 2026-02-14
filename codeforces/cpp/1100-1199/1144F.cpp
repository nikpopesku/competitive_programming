#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, u, v;
    cin >> n >> m;

    vector adj(n + 1, vector<int>());

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    return 0;
}
