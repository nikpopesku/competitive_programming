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
    ll balance = 0;

    for (const char i: k) {
        if (i == '(') {
            --left;
            ++balance;
        } else {
            --right;
            --balance;
        }
        if (balance < 0) {
            cout << "0\n";
            return 0;
        }
    }

    if (right < left) {
        cout << "0\n";
        return 0;
    }

    vector<ll> fact(left + right + 1, 1);
    for (ll i = 2; i < fact.size(); ++i) fact[i] = i * fact[i - 1] % MD;

    ll total = fact[left + right] * pow(fact[left], MD - 2) % MD * pow(fact[right], MD - 2) % MD;
    ll bad = 0;
    if (left > 0) {
        bad = fact[left + right] * pow(fact[left - 1], MD - 2) % MD * pow(fact[right + 1], MD - 2) % MD;
    }

    cout << ((total - bad) % MD + MD) % MD << '\n';
}
