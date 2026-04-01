#include <iostream>
#include <vector>

using namespace std;

#define ll long long

class Bit {
public:
    Bit(const ll sz, const vector<ll> &v) : n(sz), tree(sz + 2, 0) {
        // Build BIT over difference array D[i] = v[i] - v[i-1]
        for (ll i = 1; i <= sz; ++i) {
            update(i, v[i] - v[i - 1]);
        }
    }

    void update(ll index, const ll val) {
        while (index <= n) {
            tree[index] += val;
            index += index & -index;
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

private:
    ll n;
    vector<ll> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    // 1-indexed; v[0] = 0 as sentinel so D[1] = v[1] - v[0] = v[1]
    vector<ll> v(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    Bit bt(n, v);

    while (q--) {
        ll type;
        cin >> type;

        if (type == 1) {
            ll l, r, u;
            cin >> l >> r >> u;
            // Range [l, r] += u  =>  D[l] += u, D[r+1] -= u
            bt.update(l, u);
            if (r + 1 <= n) bt.update(r + 1, -u);
        } else {
            ll k;
            cin >> k;
            // Value at k = prefix_sum(D, k) = D[1] + ... + D[k]
            cout << bt.query(k) << '\n';
        }
    }
}
