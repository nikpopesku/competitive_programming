#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class SegTree {
public:
    SegTree(vector<int> &arr, const int sz) : n(sz), tree(sz * 4) {
        build(1, 0, n - 1, arr);
    }

    void update(const int pos, const int val) {
        update(1, 0, n - 1, pos, val);
    }

    int query(int a, int b) {
        return query(1, 0, n-1, a, b);
    }

private:
    int n;
    vector<int> tree;

    void build(const int index, const int lo, const int hi, vector<int> &arr) {
        if (lo == hi) {
            tree[index] = arr[lo];

            return;
        }

        const int mid = (lo + hi) / 2;
        build(2 * index, lo, mid, arr);
        build(2 * index + 1, mid + 1, hi, arr);

        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }

    void update(const int index, const int lo, const int hi, const int pos, const int val) {
        if (lo == hi) {
            tree[index] = val;

            return;
        }

        if (const int mid = (lo + hi) / 2; pos <= mid) {
            update(2 * index, lo, mid, pos, val);
        } else {
            update(2 * index + 1, mid + 1, hi, pos, val);
        }

        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }

    int query(const int index, const int lo, const int hi, const int a, const int b) {
        if (b < lo || a > hi) return INT_MAX;
        if (a <= lo && b >= hi) return tree[index];

        const int mid = (lo + hi) / 2;

        return min(query(2 * index, lo, mid, a, b), query(2 * index + 1, mid, hi, a, b));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, type, a, b;
    cin >> n >> q;
    vector<int> v(n);
    for (int &x: v) cin >> x;
    SegTree st(v, n);

    while (q--) {
        cin >> type >> a >> b;
        if (type == 1) {
            st.update(a - 1, b);
        } else {
            cout << st.query(a - 1, b - 1) << '\n';
        }
    }
}
