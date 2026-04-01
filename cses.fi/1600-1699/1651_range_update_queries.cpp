#include <iostream>
#include <vector>

using namespace std;

#define ll long long

class Bit {
public:
    Bit(const int sz, const vector<int> &v) : n(sz), tree(n + 1, 0) {
        for (int i = 1; i <= n; ++i) {
            update(i, v[i] - v[i - 1]);
        }
    }

    void update(int index, const int val) {
        while (index <= n) {
            tree[index] += val;
            index += index & -index;
        }
    }

    [[nodiscard]] int query(int index) const {
        int sm = 0;
        while (index > 0) {
            sm += tree[index];
            index -= index & -index;
        }

        return sm;
    }

private:
    int n;
    vector<int> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q, type, a, b, u;
    cin >> n >> q;
    vector v(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    Bit bt(n, v);

    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> a >> b >> u;
            bt.update(a, u);
            if (b + 1 <= n) {
                bt.update(b + 1, -u);
            }
        } else {
            cin >> a;
            cout << bt.query(a) << '\n';
        }
    }
}
