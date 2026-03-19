#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(n + 1, vector<int>(n + 1)) {
    }

    void update(int x, int y, const int val) {
        ++x;
        ++y;
        const int delta = val - tree[x][y];

        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= n; j += j & -j) {
                tree[i][j] += delta;
            }
        }
    }

    int range(const int x1, const int y1, const int x2, const int y2) const {
        return query(x2, y2) + query(x1 - 1, y1 - 1) - query(x2, y1 - 1) - query(x1 - 1, y2);
    }

private:
    int n;
    vector<vector<int> > tree;

    int query(const int x, const int y) const {
        int sum = 0;

        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }

        return sum;
    }
};

void solve() {
    int N, x1, y1, x2, y2, val;
    cin >> N;
    vector v(N, vector<int>(N));

    string type;
    Bit bt(N);

    while (type != "END") {
        cin >> type;

        if (type == "SET") {
            cin >> x1 >> y1 >> val;
            bt.update(x1, y1, val);
        }

        if (type == "SUM") {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << bt.range(x1, y1, x2, y2) << '\n';
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
