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
    explicit SegTree(const int sz) : n(sz), tree(sz * 4, 0) {

    }


    int query(const int l, const int r) {
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

        const int pairs = min(ans_left.matched, ans_right.close);
        Bracket merged;

        merged.matched = ans_left.matched + ans_right.matched +pairs;
        merged.open = ans_left.open - pairs + ans_right.open;
        merged.close = ans_left.close + (ans_right.close - pairs);

        return merged;
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
