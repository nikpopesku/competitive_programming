#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;


    ll ret = 0;

    for (ll a = 1; a * a * a <= n; ++a) {
        for (ll b = a; a * b * b <= n; ++b) {
            ll max_c = n / b / a;
            max_c = max_c - b + 1;

            ret += max_c;
        }
    }

    cout << ret << endl;
}