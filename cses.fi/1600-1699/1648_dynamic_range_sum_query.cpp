#include <iostream>
#include <vector>

using namespace std;

#define ll long long

class Bit {
public:
    Bit(const ll sz, const vector<ll> &v) : n(sz), tree(sz + 1, 0) {
        for (ll i = 0; i < sz; ++i) {
            update(i, v[i]);
        }
    }

    [[nodiscard]] ll query(ll index) const {
        ll sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }

    [[nodiscard]] ll sum_range(const ll left, const ll right) const {
        return query(right) - (left > 0 ? query(left - 1) : left);
    }

    void update(ll index, const ll val) {
        ++index;
        const ll delta = val - sum_range(index, index);
        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

private:
    ll n;
    vector<ll> tree;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, q, type, a, b;
    cin >> n >> q;
    vector<ll> num(n, 0);

    for (ll i = 0; i < n; ++i) {
        cin >> num[i];
    }

    Bit bt(static_cast<ll>(num.size()), num);

    for (ll i = 0; i < q; ++i) {
        cin >> type >> a >> b;

        if (type == 1) {
            bt.update(a - 1, b);
        } else {
            cout << bt.sum_range(a, b) << '\n';
        }
    }
}
