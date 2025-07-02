#include <iostream>
#include <vector>

using namespace std;

#define ll long long

class FenWick {
public:
    explicit FenWick(const vector<ll> &num): num(num) {
        bit.assign(num.size(), 0);

        for (ll i = 0; i < num.size(); ++i) {
            add_delta(i, num[i]);
        }
    }

    void update(const ll j, const ll value) {
        const ll i = j - 1;
        const ll delta = value - num[i];

        num[i] = value;

        add_delta(i, delta);
    }

    [[nodiscard]] ll sum_range(const ll l, const ll r) const {
        return sum(r - 1) - sum(l - 2);
    }

private:
    vector<ll> num;
    vector<ll> bit;

    void add_delta(ll i, const ll delta) {
        while (i < bit.size()) {
            bit[i] += delta;

            i = i | i + 1;
        }
    }

    [[nodiscard]] ll sum(ll i) const {
        ll response = 0;

        while (i >= 0) {
            response += bit[i];

            i = (i & (i + 1)) - 1;
        }

        return response;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, q, type, l, r;

    cin >> n >> q;

    vector<ll> v(n);

    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }

    auto f = FenWick(v);

    for (ll i = 0; i < q; ++i) {
        cin >> type >> l >> r;

        if (type == 2) {
            cout << f.sum_range(l, r) << "\n";
        } else {
            f.update(l, r);
        }
    }
}
