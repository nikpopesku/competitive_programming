#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, cur_product = 0, max_product = 0;
    cin >> n >> m;
    int left = 1, right = m;


    vector<ll> vc(n + 1);
    for (ll i = 1; i <= n; ++i) cin >> vc[i];
    for (int i = left; i <= right; ++i) cur_product += (i - left + 1) * vc[i];
    max_product = cur_product;

    for (int i = m + 1; i <= n; ++i) {
        left = i - m;
        right = i - 1;
        for (int j = left; j <= right; ++j) cur_product -= vc[j];
        cur_product += m * vc[i];
        max_product = max(max_product, cur_product);
    }

    cout << max_product << "\n";
}