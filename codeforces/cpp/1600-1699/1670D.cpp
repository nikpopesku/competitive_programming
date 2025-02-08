#include <iostream>

using namespace std;

#define ll long long


ll calc(ll n) {
    n--;
    ll ans = 0;
    ans = (n / 3) * (n / 3) * 3;
    for (int i = 0; i <= n % 3; i++)
        ans += (n / 3) * 2 + i;
    return ans * 2;
}

ll sol(ll n) {
    ll low = 0, high = 1e9;
    ll mid = (low + high) / 2;

    while (low <= high) {
        if (calc(mid) < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }

    return low;
}


int main() {
    ll t, n;
    cin >> t;

    for (auto i = 0; i < t; ++i) {
        cin >> n;

        cout << sol(n) << endl;
    }
}
