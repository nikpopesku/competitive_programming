#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define  ll long long

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

    void update(int index, const int val) {
        while (index <= n) {
            tree[index] += val;
            index += index & -index;
        }
    }

    int query(int l, int r) {
    }

private:
    int n;
    vector<int> tree;
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, l, r;
    cin >> n >> q;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    Bit bt(n);

    while (q--) {
        cin >> l >> r;

        bt.update(l, 1);

        if (r + 1 <= n) {
            bt.update(r + 1, -1);
        }
    }

    cout << bt.query(1, n) << '\n';
}
