#include<bits/stdc++.h>

using namespace std;

class Bit {
public:
    Bit(const int sz, vector<vector<int> > t) : n(sz), tree(n, vector<int>(n)) {
    }

    void update(int x, int y) {
        while (x <= n) {
            while (y <= n) {
                tree[x][y] ^= 1;
                y += y & -y;
            }

            x += x & -x;
        }
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
        for (int j = 0; j < n; ++i) {
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
            cout << bt.query(x1, y1, x2, y2) << '\n';

        }
    }
}
