#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> vc(n + 1, 0);

    for (ll i = 1; i <= n; ++i) {
        cin >> vc[i];
    }

    for (ll i = 1; i <= n - k; ++i) {
        if (vc[i] > vc[i + k]) {
            swap(vc[i], vc[i + k]);
        }
    }

    string response = "Yes";
    for (ll i = 1; i <= n; ++i) {
        if (vc[i] < vc[i - 1]) {
            response = "No";
            break;
        }
    }

    cout << response << '\n';
}