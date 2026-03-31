#include <iostream>
#include <vector>

using namespace std;

class SegTree {
public:
    explicit SegTree(const int sz) : n(sz), tree(sz * 4, 0) {
    }

    void update(const int pos, const int val) {
        update(1, 1, n, pos, val);
    }

    int query(const int l, const int r) {
        return query(1, 1, n, l, r);
    }

private:
    int n;
    vector<int> tree;

    int query(const int node, const int nl, const int nr, const int l, const int r) {
        if (r < nl || l > nr) {
            return 0;
        }

        if (l <= nl && r >= nr) {
            return tree[node];
        }

        const int mid = (nl + nr) / 2;
        const int ans_left = query(node * 2, nl, mid, l, r);
        const int ans_right = query(node * 2 + 1, mid + 1, nr, l, r);

        return ans_left + ans_right;
    }

    void update(const int node, const int nl, const int nr, const int pos, const int val) {
        if (nl == nr) {
            tree[node] = val;

            return;
        }

        if (const int mid = (nr + nl) / 2; pos <= mid) {
            update(node * 2, nl, mid, pos, val);
        } else {
            update(node * 2 + 1, mid + 1, nr, pos, val);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;
    int l, r;
    SegTree st(static_cast<int>(s.size()) + 1);

    for (int i = 0; i < s.size(); ++i) {
        st.update(i, 1);
    }

    while (n--) {
        cin >> l >> r;
        cout << st.query(l, r) << '\n';
    }
}
