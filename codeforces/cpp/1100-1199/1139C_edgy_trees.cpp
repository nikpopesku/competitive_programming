#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, u, v, x;
    cin >> n >> k;
    vector adj(n+1, vector<int>());

    for (int i = 1; i <= n - 1; ++i) {
        cin >> u >> v >> x;
        if (x == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}
