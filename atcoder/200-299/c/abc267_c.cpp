#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, cur_product = 0, cur_sum = 0, max_product = 0;
    cin >> n >> m;

    vector<ll> vc(n + 1);

    for (ll i = 1; i <= m; ++i) {
        cin >> vc[i];
        cur_product += i * vc[i];
        cur_sum += vc[i];
    }
    max_product = cur_product;

    for (ll i = m + 1; i <= n; ++i) {
        cin >> vc[i];
        cur_product += -cur_sum + m * vc[i];
        cur_sum += -vc[i - m] + vc[i];
        max_product = max(max_product, cur_product);
    }

    cout << max_product << "\n";
}