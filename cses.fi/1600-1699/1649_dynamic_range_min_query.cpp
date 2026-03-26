#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class SegTree {
public:
    explicit SegTree(vector<int> arr) : n(static_cast<int>(arr.size())), tree(n * 4) {
        build(arr, 1, 0, n - 1);
    }

    void update(const int a, const int b) {
        update(1, 0, n - 1, a, b);
    }

    int query(const int a, const int b) {
        return query(1, 0, n - 1, a, b);
    }

private:
    int n;
    vector<int> tree;

    int update(const int index, const int lo, const int hi, const int pos, const int val) {
        if (lo == hi) {
            tree[index] = val;

            return tree[index];
        }

        const int mid = (lo + hi) / 2;
        if (pos <= mid) update(2 * index, lo, mid, pos, val);
        else            update(2 * index + 1, mid + 1, hi, pos, val);
        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
        return tree[index];
    }

    int query(const int index, const int lo, const int hi, const int a, const int b) {
        if (b < lo || a > hi) return INT_MAX;
        if (a <= lo && hi <= b) return tree[index];

        const int mid = (lo + hi) / 2;
        return min(query(2 * index, lo, mid, a, b), query(2 * index + 1, mid + 1, hi, a, b));
    }

    void build(vector<int> &arr, const int index, const int lo, const int hi) {
        if (lo == hi) {
            tree[index] = arr[lo];
            return;
        }

        const int mid = (lo + hi) / 2;
        build(arr, 2 * index, lo, mid);
        build(arr, 2 * index + 1, mid + 1, hi);
        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, type, a, b;
    cin >> n >> q;

    vector<int> v(n);
    for (int &x: v) cin >> x;

    SegTree st(v);

    while (q--) {
        cin >> type >> a >> b;

        if (type == 1) {
            st.update(a - 1, b);
        } else {
            cout << st.query(a - 1, b - 1) << '\n';
        }
    }
}
