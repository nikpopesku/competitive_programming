#include <iostream>
#include <vector>
#include <unordered_map>
#include <ranges>
#include <algorithm>

using namespace std;

int solve(const int &n, const int &k, unordered_map<int, int> &mp, const vector<int> &a) {
    // Check if all frequencies are divisible by k
    for (const auto &freq: mp | views::values) {
        if (freq % k != 0) {
            return 0;
        }
    }

    long long response = n; // All subarrays of length 1 are valid
    
    // Special case: only one unique element
    if (mp.size() == 1) {
        long long max_len = n / k;
        // Sum of valid windows for each starting position
        // Position 0: (max_len - 1) windows (lengths 2 to max_len)
        // Position 1: (max_len - 1) windows
        // ...
        // Position n - max_len: (max_len - 1) windows
        // Position n - max_len + 1: (max_len - 2) windows (lengths 2 to max_len - 1)
        // ...
        // Position n - 2: 1 window (length 2)
        
        if (max_len >= 2) {
            // Full windows: positions [0, n - max_len] contribute (max_len - 1) each
            long long full_positions = max(0LL, n - max_len + 1);
            response += full_positions * (max_len - 1);
            
            // Partial windows: positions [n - max_len + 1, n - 2]
            // Position n - max_len + 1: max_len - 2 windows
            // Position n - max_len + 2: max_len - 3 windows
            // ...
            // Position n - 2: 1 window
            // This is sum of 1 + 2 + ... + (max_len - 2) = (max_len - 2) * (max_len - 1) / 2
            long long partial_positions = min(max_len - 1, (long long)n - full_positions);
            if (partial_positions > 0) {
                response += (partial_positions - 1) * partial_positions / 2;
            }
        }
        return response;
    }
    
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
            int len = r - l + 1;
            if (len >= 2 && len <= n / k) {
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
