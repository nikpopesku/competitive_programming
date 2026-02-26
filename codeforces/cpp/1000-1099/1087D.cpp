#include <iostream>
#include <vector>
#include <iomanip>

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

    int counter = 0;

    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == 1) {
            ++counter;
        }
    }

    cout << fixed << setprecision(18) << 2 * static_cast<double>(s) / counter << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
