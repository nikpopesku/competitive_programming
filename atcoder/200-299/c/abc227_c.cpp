#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main() {
    cin >> n;
    ll ret = 0;
    for (ll a = 1; a * a * a <= n; a++) {
        for (ll b = a; a * b * b <= n; b++) {
            ll max_c = n / a / b;
            ret += max_c - b + 1;
        }
    }
    cout << ret << endl;
}