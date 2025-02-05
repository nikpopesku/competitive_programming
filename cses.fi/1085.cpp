#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll count_subarray(ll val, vector<ll> &vc) {
    ll response = 0;
    ll current_sum = 0;

    for (ll i = 0; i < vc.size(); ++i) {
        if (current_sum + vc[i] <= val) {
            current_sum += vc[i];
        } else {
            ++response;
            current_sum = vc[i];
        }
    }

    if (current_sum > 0) ++response;

    return response;
}

int main() {
    ll n, k, total_sum = 0, max_elem = 0;
    std::cin >> n >> k;

    std::vector<ll> vc(n);

    for (ll i = 0; i < n; ++i) {
        cin >> vc[i];
        total_sum += vc[i];
        if (vc[i] > max_elem) max_elem = vc[i];
    }

    ll left = max_elem, right = total_sum;

    while (left < right) {
        ll m = left + (right - left + 1) / 2;

        ll value = count_subarray(m, vc);

        if (value < k) {
            right = m - 1;
        } else {
            left = m;
        }
    }

    cout <<  left << endl;
}