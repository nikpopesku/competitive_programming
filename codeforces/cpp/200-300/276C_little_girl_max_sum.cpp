#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define  ll long long

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, l, r;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<ll> count(n + 1, 0);

    while (q--) {
        cin >> l >> r;
        count[l - 1]++;
        if (r < n) {
            --count[r];
        }
    }

    for (int i = 1; i <= n; ++i) {
        count[i] += count[i - 1];
    }

    ranges::sort(v);
    sort(count.begin(), count.begin() + n);

    ll response = 0;

    for (int i = 0; i < n; ++i) {
        response += count[i] * v[i];
    }

    cout << response << '\n';
}
