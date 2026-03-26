#include <iostream>
#include <vector>
using namespace std;

class SegTree {
public:
    SegTree(vector<int> arr) : n(static_cast<int>(arr.size())), tree(n * 4) {
        build(arr, 1, 0, n - 1);
    }

private:
    int n;
    vector<int> tree;

    void build(vector<int> &arr, const int index, const int lo, const int hi) {
        if (lo == hi) {
            tree[index] = arr[lo];
            return;
        }

        const int mid = (lo + hi) / 2;
        build(arr, index, lo, mid);
        build(arr, index, mid + 1, hi);
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

        if (type == 1)

    }
}
