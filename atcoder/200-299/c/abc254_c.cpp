#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> vc(n);

    for (ll i = 0; i < n; ++i) {
        cin >> vc[i];
    }

    for (ll i = 0; i < n; ++i) cout << vc[i] << ' ';
}