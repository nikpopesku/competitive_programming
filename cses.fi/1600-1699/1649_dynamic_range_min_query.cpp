#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegTree {
    int n;
    vector<int> tree;

    void build(const vector<int> &arr, const int node, const int lo, const int hi) {
        if (lo == hi) {
            tree[node] = arr[lo];
            return;
        }
        const int mid = (lo + hi) / 2;
        build(arr, 2 * node, lo, mid);
        build(arr, 2 * node + 1, mid + 1, hi);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    void update(const int node, const int lo, const int hi, const int pos, const int val) {
        if (lo == hi) {
            tree[node] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if (pos <= mid) update(2 * node, lo, mid, pos, val);
        else update(2 * node + 1, mid + 1, hi, pos, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(const int node, const int lo, const int hi, const int a, const int b) {
        if (b < lo || hi < a) return INT_MAX; // fully outside
        if (a <= lo && hi <= b) return tree[node]; // fully inside
        int mid = (lo + hi) / 2;
        return min(query(2 * node, lo, mid, a, b),
                   query(2 * node + 1, mid + 1, hi, a, b));
    }

public:
    explicit SegTree(const vector<int> &arr) : n(arr.size()), tree(4 * arr.size()) {
        build(arr, 1, 0, n - 1);
    }

    void update(int pos, int val) { update(1, 0, n - 1, pos, val); }
    int query(int a, int b) { return query(1, 0, n - 1, a, b); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto &x: arr) cin >> x;

    SegTree st(arr);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) st.update(a - 1, b); // 1-indexed -> 0-indexed
        else cout << st.query(a - 1, b - 1) << '\n';
    }
}
