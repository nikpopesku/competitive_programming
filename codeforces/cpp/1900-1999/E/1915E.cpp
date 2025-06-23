#include <iostream>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    long long diff = 0, value;
    set<long long> s;
    s.insert(0);

    bool response = false;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        if (i % 2 == 1) {
            diff += value;
        } else {
            diff -= value;
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
