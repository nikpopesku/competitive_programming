#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class SegTree {
public:
    SegTree(vector<int> &arr, const int sz) : n(sz), tree(sz * 4) {
        build(1, 0, n - 1, arr);
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int &x: v) cin >> x;
    SegTree st(v, n);

    while (q--) {
    }
}
