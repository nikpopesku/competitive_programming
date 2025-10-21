#include <iostream>
#include <vector>
#include <map>
#include <ranges>

using namespace std;

int solve(int &n, int &k, const map<int, int> &mp) {
    for (const auto &val: mp | views::values) {
        if (val % k != 0) {
            return 0;
        }
    }

    for (int i = 1; i <= n / k; ++i) {
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]] += 1;
        }

        cout << solve(n, k, mp) << "\n";
    }

    return 0;
}
