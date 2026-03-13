#include <iostream>
#include <vector>

using namespace std;

#define ll long long

class Bit {
public:
    Bit(const int sz, const vector<int> &v) : n(sz), tree(sz + 1, 0) {
        for (int i = 0; i < sz; ++i) {
            update(i, v[i]);
        }
    }

    int query(int index) const {
        ++index;
        int sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }

    int sum_range(const int right, const int left) const {
        return query(right) - (left > 0 ? query(left - 1) : left);
    }

    void update(int index, const int val) {
        const int delta = val - sum_range(index, index);
        ++index;
        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

private:
    int n;
    vector<int> tree;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q, type, a, b;
    cin >> n >> q;
    vector<int> num(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    Bit bt(static_cast<int>(num.size()), num);

    for (int i = 0; i < q; ++i) {
        cin >> type >> a >> b;

        if (type == 1) {
            bt.update(a, b);
        } else {
            cout << bt.sum_range(a, b) << '\n';
        }
    }
}
