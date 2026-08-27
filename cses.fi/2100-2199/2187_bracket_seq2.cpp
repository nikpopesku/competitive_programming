#include<bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;

ll pow(ll a, ll b) {
    ll result = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            result = result * a % MD;
            --b;
        } else {
            b >>= 1;
            a = a * a % MD;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    string k;
    cin >> k;

    if (n % 2 == 1) {
        cout << "0\n";
        return 0;
    }

    ll left = n / 2;
    ll right = n / 2;

    for (const auto i: k) {
        if (i == '(') {
            --left;
        } else {
            --right;
        }

        if (right < left) {
            cout << "0\n";
            return 0;
        }
    }

    ll total = 0;
    ll bad = 0;
    vector<ll> fact(left + right + 1, 1);
    for (ll i = 2; i <= left + right; ++i) fact[i] = i * fact[i - 1];

    total = fact[left + right] * pow(fact[left], MD - 2) % MD * pow(fact[right], MD - 2) % MD;

    if (left > 1) {
        bad = fact[left + right] * pow(fact[left - 1], MD - 2) % MD * pow(fact[right + 1], MD - 2) % MD;
    }

    cout << ((total - bad) % MD + MD) % MD;
}
