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
    SegTree(const int sz, const string &s) : n(sz), tree(sz * 4) {
        for (int i = 0; i < s.size(); ++i) {
            const Bracket br = s[i] == '(' ? Bracket{0, 1, 0} : Bracket{0, 0, 1};
            build(1, 1, n, i + 1, br);
        }
    }

    Bracket query(const int l, const int r) {
        return query(1, 1, n, l, r);
    }

private:
    int n;
    vector<Bracket> tree;

    void build(const int node, const int nl, const int nr, const int pos, const Bracket val) {
        if (nl == nr) {
            tree[node] = val;

            return;
        }

        if (const int mid = (nl + nr) / 2; pos <= mid) {
            build(node * 2, nl, mid, pos, val);
        } else {
            build(node * 2 + 1, mid + 1, nr, pos, val);
        }

        Bracket merged{};
        const int pairs = min(tree[node * 2].open, tree[node * 2 + 1].close);
        merged.matched = tree[node * 2].matched + tree[node * 2 + 1].matched + pairs;
        merged.open = tree[node * 2].open + tree[node * 2 + 1].open - pairs;
        merged.close = tree[node * 2].close + tree[node * 2 + 1].close - pairs;
    }

    Bracket query(const int node, const int nl, const int nr, const int l, const int r) {
        if (r < nl || l > nr) {
            return {};
        }

        if (l <= nl && r >= nr) {
            return tree[node];
        }

        const int mid = (nl + nr) / 2;
        auto ans_left = query(node * 2, nl, mid, l, r);
        auto ans_right = query(node * 2 + 1, mid + 1, nr, l, r);

        Bracket merged{};
        const int pairs = min(ans_left.open, ans_right.close);
        merged.matched = ans_left.matched + ans_right.matched + pairs;
        merged.open = ans_left.open + ans_right.open - pairs;
        merged.close = ans_right.close + ans_left.close - pairs;

        return merged;
    }
};


int main() {
    string s;
    cin >> s;
    int m, l, r;
    cin >> m;
    SegTree st(static_cast<int>(s.size()), s);

    while (m--) {
        cin >> l >> r;
        cout << st.query(l, r).matched << '\n';
    }
}
