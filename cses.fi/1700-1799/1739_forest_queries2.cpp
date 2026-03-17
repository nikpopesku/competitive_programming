#include<bits/stdc++.h>

using namespace std;

class Bit {
public:
    Bit(const int sz, vector<vector<int> > t) : n(sz), tree(n + 1, vector<int>(n + 1)) {
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (t[x][y]) {
                    update(x + 1, y + 1);
                }
            }
        }
    }

    void update(const int x, const int y) {
        const int y0 = y;

        for (int i = x; i <= n; i += i & -i) {
            for (int j = y0; j <= n; j += j & -j) {
                tree[i][j] ^= 1;
            }
        }
    }

    [[nodiscard]] int query(const int x, const int y) const {
        int sum = 0;
        const int y0 = y;

        for (int i = x; i > 0; i -= x & -x) {
            for (int j = y0; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }

        return sum;
    }

    [[nodiscard]] int range(const int x1, const int y1, const int x2, const int y2) const {
        return query(x2, y2) + query(x1 - 1, y1 - 1) - query(x2, y1 - 1) - query(x1 - 1, y2);
    }

private:
    int n;
    vector<vector<int> > tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q, type, x1, y1, x2, y2;
    cin >> n >> q;
    vector forest(n, vector<int>(n));
    char val;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> val;
            forest[i][j] = val == '*' ? 1 : 0;
        }
    }

    Bit bt(n, forest);

    for (int i = 0; i < q; ++i) {
        cin >> type;

        if (type == 1) {
            cin >> y1 >> x1;
            bt.update(x1, y1);
        } else {
            cin >> y1 >> x1 >> y2 >> x2;
            cout << bt.range(x1, y1, x2, y2) << '\n';
        }
    }
}
