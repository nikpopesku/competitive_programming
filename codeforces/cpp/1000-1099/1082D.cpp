#include <iostream>
#include <list>
#include <vector>


using namespace std;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0);
    vector leaves(n, false);
    vector adj(n, vector<int>());
    list<pair<int, int> > q;
    int m = 0;
    int d = 0;
    int value;

    for (int i = 0; i < n; i++) {
        cin >> value;
        a[i] += value;

        if (value <= 1) {
            leaves[i] = true;
        } else if (q.empty()) {
            q.emplace_back(i, a[i]);
        } else {
            auto elem = q.back();
            q.pop_back();
            adj[i].push_back(elem.first);
            ++m;
            --a[i];
            --a[elem.first];

            if (a[elem.first] > 0) {
                q.emplace_back(elem.first, a[elem.first]);
            }

            if (a[i] > 0) {
                q.emplace_back(i, a[i]);
            }
        }
    }

    if (a[n - 1] > 0 && leaves[n - 1] == false) {
        q.emplace(n - 1, a[n - 1]);
    }

    for (int leaf = 0; leaf < n; ++leaf) {
        if (leaves[leaf] == false) {
            continue;
        }

        if (a[leaf] > 0) {
            if (q.empty()) {
                cout << "NO\n";

                return;
            }

            if (q.size() == 1 && q.front().first == leaf) {
                cout << "NO\n";

                return;
            }

            auto elem = q.front();
            q.pop();

            if (elem.first == leaf) {
                q.emplace(elem.first, elem.second);
            }

            adj[leaf].push_back(elem.first);
            ++m;

            if (elem.second > 1) {
                q.emplace(elem.first, elem.second - 1);
            }
        }
    }

    cout << "YES" << " " << d + 2 << "\n";
    cout << m << "\n";

    for (int i = 0; i < n; ++i) {
        for (const auto nei: adj[i]) {
            cout << i + 1 << ' ' << nei + 1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
