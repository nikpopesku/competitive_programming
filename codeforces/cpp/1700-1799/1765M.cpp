#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = 1;

        for (int d = 2; d * d <= n; ++d) {
            if (n % d == 0) {
                a = n / d;
                break;
            }
        }

        cout << a << ' ' << n - a << "\n";
    }
}