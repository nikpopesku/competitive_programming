#include <iostream>
#include <stack>
#include <vector>


using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> leaves;
    vector adj(n, vector<int>());
    stack<pair<int, int> > st;
    int value;

    for (int i = 0; i < n; i++) {
        cin >> value;
        a[i] += value;

        if (value <= 1) {
            leaves.push_back(i);
        } else if (i < n - 1) {
            adj[i].push_back(i + 1);
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
            auto elem = st.top();
            st.pop();
            adj[leaf].push_back(elem.first);

            if (elem.second > 1) {
                st.emplace(elem.first, elem.second - 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
