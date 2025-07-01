#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
