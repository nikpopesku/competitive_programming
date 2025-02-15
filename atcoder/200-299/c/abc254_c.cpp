#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> vc(n + 1, 0), pos(n + 1, 0);

    for (ll i = 1; i <= n; ++i) {
        cin >> vc[i];
        pos[vc[i]] = i;
    }

    for (ll i = 1; i <= n - k; ++i) {
        if (pos[i] != i) {
            swap(vc[i], vc[i + k]);
            swap(pos[i], pos[i + k]);
        }
    }

    string response = "Yes";
    for (ll i = 1; i <= n; ++i) {
        if (i != vc[i]) {
            response = "No";
            break;
        }
    }

    cout << response << '\n';
}