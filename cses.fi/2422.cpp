#include <iostream>

using namespace std;

#define ll long long

ll count_in_matrix(ll x, ll n) {
    ll count = 0;

    for (int i = 1; i <= n; ++i) {
        count += min(x / i, n);
    }

    return count;
}

int main() {
    ll n;
    cin >> n;
    ll middle_elem = (n * n - 1) / 2;

    ll left = 1, right = n * n;

    while (left < right) {
        ll m = left + (right - left) / 2;

        if (count_in_matrix(m, n) <= middle_elem) {
            left = m  + 1;
        } else {
            right = m;
        }
    }

    cout << left << endl;
}