#include <iostream>
#include <vector>


using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> leaves;
    vector adj(n, vector<int>());
    vector degree(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < n - 1) {
            adj[i].push_back(i + 1);
            --a[i];
            --a[i+1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
