#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, s, a, b;
    cin >> n >> s;
    vector adj(n + 1, vector<int>());

    for (int i = 1; i <= n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
