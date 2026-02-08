#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> internal;
    vector<int> leaves;
    internal.reserve(n);
    leaves.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            leaves.push_back(i);
        } else {
            internal.push_back(i);
        }
    }

    if (internal.empty()) {
        cout << "NO\n";
        return;
    }

    vector<pair<int, int> > edges;
    edges.reserve(n - 1);

    if (internal.size() == 1) {
        int center = internal[0];
        if (a[center] < n - 1) {
            cout << "NO\n";
            return;
        }
        for (int leaf : leaves) {
            edges.emplace_back(center, leaf);
        }
        cout << "YES 2\n";
        cout << edges.size() << "\n";
        for (const auto &e : edges) {
            cout << e.first + 1 << ' ' << e.second + 1 << "\n";
        }
        return;
    }

    sort(internal.begin(), internal.end(), [&](int lhs, int rhs) {
        if (a[lhs] != a[rhs]) {
            return a[lhs] > a[rhs];
        }
        return lhs < rhs;
    });

    for (size_t i = 0; i + 1 < internal.size(); ++i) {
        edges.emplace_back(internal[i], internal[i + 1]);
    }

    vector<int> remaining(n, 0);
    for (size_t i = 0; i < internal.size(); ++i) {
        int node = internal[i];
        int used = (i == 0 || i + 1 == internal.size()) ? 1 : 2;
        remaining[node] = a[node] - used;
        if (remaining[node] < 0) {
            cout << "NO\n";
            return;
        }
    }

    int diameter = static_cast<int>(internal.size()) - 1;
    size_t leaf_idx = 0;

    if (leaf_idx < leaves.size()) {
        int leaf = leaves[leaf_idx++];
        edges.emplace_back(internal.front(), leaf);
        --remaining[internal.front()];
        ++diameter;
    }
    if (leaf_idx < leaves.size()) {
        int leaf = leaves[leaf_idx++];
        edges.emplace_back(internal.back(), leaf);
        --remaining[internal.back()];
        ++diameter;
    }

    size_t internal_idx = 0;
    while (leaf_idx < leaves.size()) {
        while (internal_idx < internal.size() &&
               remaining[internal[internal_idx]] == 0) {
            ++internal_idx;
        }
        if (internal_idx == internal.size()) {
            cout << "NO\n";
            return;
        }
        int node = internal[internal_idx];
        edges.emplace_back(node, leaves[leaf_idx++]);
        --remaining[node];
    }

    cout << "YES " << diameter << "\n";
    cout << edges.size() << "\n";
    for (const auto &e : edges) {
        cout << e.first + 1 << ' ' << e.second + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
