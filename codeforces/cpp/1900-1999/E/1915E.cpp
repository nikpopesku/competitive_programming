#include <iostream>
#include <set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int diff = 0;
    set<int> s;
    s.insert(0);

    bool response = false;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i % 2 == 1) {
            diff += v[i];
        } else {
            diff -= v[i];
        }

        if (!response and s.count(diff)) {
            response = true;
        } else {
            s.insert(diff);
        }
    }

    cout << (response ? "YES" : "NO") << "\n";

}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
