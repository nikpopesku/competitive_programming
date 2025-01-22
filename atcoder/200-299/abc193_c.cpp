#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

int main() {
    ll N = 10e10;
    std::vector<ll> vc;
    ll n;
    std::cin >> n;

    ll i = 2, j = 2;
    ll val_i = 2 * 2, val_j = 2 * 2 * 2;

    while (val_i <= N or val_j <= N) {
        if (val_i < val_j) {
            vc.push_back(val_i);
            i++;
            val_i = i * i;
        } else {
            vc.push_back(val_j);
            j++;
            val_j = j * j * j;
        }
    }

    ll left = 0, right = vc.size() - 1;
    ll m = left;

    while (left < right) {
        m = left + (right - left) / 2;

        if (vc[m + 1] <= n) {
            left = m + 1;
        } else {
            right = m;
        }
    }

    std::cout << n - m << std::endl;
}