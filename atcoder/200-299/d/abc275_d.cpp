#include<bits/stdc++.h>

using namespace std;

#define ll long long

unordered_map<ll, ll> mp;

ll calc(ll n) {
    if (n == 0) return 1;
    if (mp.contains(n)) return mp[n];

    return calc(n / 2) + calc(n / 3);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    cout << calc(n) << "\n";
}