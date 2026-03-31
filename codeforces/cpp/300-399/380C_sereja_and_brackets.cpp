#include <iostream>
#include <vector>

using namespace std;

struct Bracket {
    int matched;
    int open;
    int close;
};

class SegTree {
public:
    explicit SegTree(const int sz, string s) : n(sz), tree(sz * 4) {
        for (int i = 0; i < n; ++i) {
            const Bracket br = (s[i] == '(') ? Bracket{0, 1, 0} : Bracket{0, 0, 1};
            build(1, 1, n, i + 1, br);
        }
    }


    Bracket query(const int l, const int r) {
        return query(1, 1, n, l, r);
    }

private:
    int n;
    vector<Bracket> tree;

    Bracket query(const int node, const int nl, const int nr, const int l, const int r) {
        if (r < nl || l > nr) {
            return {};
        }

        if (l <= nl && r >= nr) {
            return tree[node];
        }

        const int mid = (nl + nr) / 2;
        const Bracket ans_left = query(node * 2, nl, mid, l, r);
        const Bracket ans_right = query(node * 2 + 1, mid + 1, nr, l, r);

        const int pairs = min(ans_left.open, ans_right.close);
        Bracket merged;

        merged.matched = ans_left.matched + ans_right.matched +pairs;
        merged.open = ans_left.open - pairs + ans_right.open;
        merged.close = ans_left.close + (ans_right.close - pairs);

        return merged;
    }

    void build(const int node, const int nl, int nr, int pos, Bracket val) {
        if (nl == nr) {
            tree[node] = val;
            return;
        }
        const int mid = (nl + nr) / 2;
        if (pos <= mid)
            build(node * 2, nl, mid, pos, val);
        else
            build(node * 2 + 1, mid + 1, nr, pos, val);

        const int pairs = min(tree[node * 2].open, tree[node * 2 + 1].close);
        tree[node].matched = tree[node*2].matched + tree[node*2+1].matched + pairs;
        tree[node].open    = tree[node*2].open - pairs + tree[node*2+1].open;
        tree[node].close   = tree[node*2].close + (tree[node*2+1].close - pairs);
    }
};

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;
    int l, r;
    SegTree st(static_cast<int>(s.size()), s);

    while (n--) {
        cin >> l >> r;
        cout << 2 * st.query(l, r).matched << '\n';
    }
}
