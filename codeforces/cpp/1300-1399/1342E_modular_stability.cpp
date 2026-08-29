#include <iostream>
#include <vector>

using namespace std;

#define ll long long

constexpr ll MD = 998244353;

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
    ll n, k;
    cin >> n >> k;
    ll num_stable_arr = 0;
    vector<ll> fact(n + 1, 1);
    for (ll i = 2; i <= n; ++i) fact[i] = i * fact[i - 1] % MD;

    for (ll i = 1; i <= n / k; ++i) {
        num_stable_arr = (num_stable_arr + fact[n / i - 1] * pow(fact[k - 1], MD - 2) % MD * pow(
                              fact[n / i - k], MD - 2) % MD) % MD;
    }

    cout << num_stable_arr << '\n';
}
