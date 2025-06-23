#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), partial_sum_even(n + 1, 0), partial_sum_odd(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i > 0 and i % 2 == 1) {
            partial_sum_odd[i] = partial_sum_odd[i - 1] + v[i];
            partial_sum_even[i] = partial_sum_even[i - 1];
        } else if (i > 0) {
            partial_sum_odd[i] = partial_sum_odd[i - 1];
            partial_sum_even[i] = partial_sum_even[i - 1] + v[i];
        }
    }

    string response = "NO";

    for (int l = 0; l <= n - 1; ++l) {
        for (int r = l + 1; r <= n; ++r) {
            if (partial_sum_even[r] - partial_sum_even[l] == partial_sum_odd[r] - partial_sum_odd[l]) {
                response = "YES";
                break;
            }
        }

        if (response == "YES") break;
    }

    cout << response << "\n";

}


int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
