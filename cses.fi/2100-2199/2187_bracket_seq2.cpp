#include<bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;

ll pow(ll a, ll b) {
    ll response = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            response = response * a % MD;
            --b;
        } else {
            a = a * a % MD;
            b >>= 1;
        }
    }

    return response;
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


    for (const char i: k) {
        if (i == '(') {
            --left;
        } else {
            --right;
        }
    }

    if (right < left) {
        cout << "0\n";
        return 0;
    }

    vector<ll> fact(left + right + 1, 1);
    for (ll i = 2; i < fact.size(); ++i) fact[i] = i * fact[i - 1] % MD;

    cout << fact[left + right] * pow(fact[left], MD - 2) % MD * pow(fact[right], MD - 2) % MD << '\n';
}
