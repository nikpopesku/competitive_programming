#include <iostream>
#include <stack>
#include <vector>


using namespace std;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0);
    vector<int> leaves;
    vector adj(n, vector<int>());
    stack<pair<int, int> > st;
    int m = 0;
    int value;

    for (int i = 0; i < n; i++) {
        cin >> value;
        a[i] += value;

        if (value <= 1) {
            leaves.push_back(i);
        } else if (i < n - 1) {
            adj[i].push_back(i + 1);
            ++m;
            --a[i];
            --a[i + 1];

            if (a[i] > 0) {
                st.emplace(i, a[i]);
            }
        }
    }

    if (a[n - 1] > 0) {
        st.emplace(n - 1, a[n - 1]);
    }

    for (const int leaf: leaves) {
        if (a[leaf] > 0) {
            if (st.empty()) {
                cout << "NO\n";

                return;
            }

            auto elem = st.top();
            st.pop();
            adj[leaf].push_back(elem.first);
            ++m;

            if (elem.second > 1) {
                st.emplace(elem.first, elem.second - 1);
            }
        }
    }

    cout << "YES\n";
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
