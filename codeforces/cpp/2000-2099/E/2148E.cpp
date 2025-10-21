#include <iostream>
#include <vector>
#include <unordered_map>
#include <ranges>

using namespace std;

int solve(const int &n, const int &k, unordered_map<int, int> &mp, const vector<int> &a) {
    // Check if all frequencies are divisible by k
    for (const auto &freq: mp | views::values) {
        if (freq % k != 0) {
            return 0;
        }
    }

    long long response = n; // All subarrays of length 1 are valid
    
    // Precompute limits
    unordered_map<int, int> limit;
    for (const auto &[num, freq]: mp) {
        limit[num] = freq / k;
    }

    // For each starting position, find maximum valid window
    for (int l = 0; l < n; ++l) {
        unordered_map<int, int> cnt;
        
        // Find the rightmost position where window [l, r] is valid
        for (int r = l; r < n; ++r) {
            cnt[a[r]]++;
            
            // If we exceeded the limit, stop
            if (cnt[a[r]] > limit[a[r]]) {
                break;
            }
            
            // Count this window if length is in [2, n/k]
            if (const int len = r - l + 1; len >= 2 && len <= n / k) {
                response++;
            }
        }
    }

    return response;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
        }

        cout << solve(n, k, mp, a) << "\n";
    }

    return 0;
}
