#include <iostream>
#include <vector>

using namespace std;

#define ll long long

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(n + 1, 0) {
    }

    void update(int index, const int val) {
        const int delta = val - tree[index];

        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int range(const int a, const int b) {
        return query(b) - query(a - 1);
    }

private:
    int n;
    vector<int> tree;

    int query(int index) {
        return 4;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q, type, a, b, val;
    cin >> n >> q;

    Bit bt(n);

    for (int i = 0; i < n; ++i) {
        cin >> val;
        bt.update(i + 1, val);
    }

    for (int i = 0; i < q; ++i) {
        cin >> type >> a >> b;
    }
}
