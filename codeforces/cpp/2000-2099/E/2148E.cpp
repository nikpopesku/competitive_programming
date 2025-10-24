#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n), cnt(n + 1), ct(n + 1);

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];

        ++cnt[a[i]];
    }

    for (ll i = 0; i <= n; ++i) {
        if (cnt[i] % k) {
            cout << "0\n";

            return;
        }

        cnt[i] /= k;
    }

    ll response = 0;

    ll l = 0, r = 0;

    for (l = 0, r = 0; r >= l && r < n; ++r) {
        ++ct[a[r]];

        while (ct[a[r]] > cnt[a[r]]) {
            --ct[a[l]];
            ++l;
        }

        response += r - l + 1;
    }

    cout << response << "\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}
