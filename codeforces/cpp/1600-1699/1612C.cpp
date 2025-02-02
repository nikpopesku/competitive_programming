#include <iostream>

using namespace std;

#define ll long long

int main() {
    int t;
    ll k, x;
    cin >> t;
    cin >> k >> x;

    ll first_half = (k + 1) * k / 2;

    if (first_half >= x) {
        ll left = 0, right = k;

        while (left < right) {
            ll m = left + (right - left + 1) / 2;

            ll value = (1 + m) * m / 2;
            if (value < x) {
                left = m;
            } else {
                right = m - 1;
            }
        }

        cout << left << endl;
    } else {
        ll left = 0, right = k;

        while (left < right) {
            ll m = left + (right - left + 1) / 2;

            ll value = (1 + m) * m / 2;
            if (value < x) {
                left = m;
            } else {
                right = m - 1;
            }
        }

        cout << left << endl;
    }
}
