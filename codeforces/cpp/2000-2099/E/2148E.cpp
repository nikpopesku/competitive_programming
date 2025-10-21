#include <iostream>
#include <vector>
#include <map>
#include <ranges>

using namespace std;

bool check(map<int, int> &mp, const map<int, int> &m, const int &k) {
    for (const auto &[number, frequency]: m) {
        if (frequency > mp[number] / k) {
            return false;
        }
    }

    return true;
}

int solve(const int &n, const int &k, map<int, int> &mp, const vector<int> &a) {
    for (const auto &val: mp | views::values) {
        if (val % k != 0) {
            return 0;
        }
    }

    int response = n;

    for (int len = 2; len <= n / k; ++len) {
        map<int, int> m;
        int l = 0;

        for (int i = 0; i <= len - 1; ++i) {
            m[a[i]] += 1;
        }


        for (int r = len - 1; r <= n - 1; ++r) {
            if (check(mp, m, k)) {
                for (auto &[number, frequency]: m) {
                    if (frequency > mp[number] / k) {
                        return response;
                    }
                }

                ++response;
            }

            if (r != n - 1) {
                m[a[r + 1]] += 1;
                m[a[l]] -= 1;
                if (m[a[l]] == 0) {
                    m.erase(a[l]);
                }
                ++l;
            }
        }
    }

    return response;
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

        cout << solve(n, k, mp, a) << "\n";
    }

    return 0;
}
