#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

#define          all(v)              v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int sum = a[0];
    if (sum != 1) {
        cout << "NO\n";
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (sum < a[i]) {
            cout << "NO\n";
            return;
        }

        sum += a[i];
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}