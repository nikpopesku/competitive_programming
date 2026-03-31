#include <iostream>
#include <vector>

using namespace std;

class SegTree {
public:
    SegTree(int sz): n(sz), tree(sz * 4, 0) {

    }

    void update(int pos, int val) {
        update(1, 1, n, pos, val);
    }

    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }
private:
    int n;
    vector<int> tree;

    int query(int node, int nl, int nr, int l, int r) {
        if (r < nl || l > nr) {
            return 0;
        }

        if (l <= nl && r >= nr) {
            return tree[node];
        }

        int mid = (nl + nr) / 2;
        int ans_left = query(node * 2, nl, mid, l , r);
        int ans_right = query(node * 2 + 1, mid +1 , nr, l, r);

        return ans_left + ans_right;
    }
};

int main()
{
    string s;
    cin >> s;

    int n;
    cin >> n;
    int l, r;
    SegTree st(10);

    while (n--) {
        cin >> l >> r;
    }
}