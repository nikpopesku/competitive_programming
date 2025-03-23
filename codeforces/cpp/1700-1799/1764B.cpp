#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vc(n);

        for (int i = 0; i < n; ++i) cin >> vc[i];
        int gcd_val = vc[0];
        for (int i = 1; i < n; ++i) gcd_val = gcd(gcd_val, vc[i]);


        cout << *vc.rbegin() / gcd_val << "\n";
    }
}