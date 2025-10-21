#include <iostream>
#include <vector>
#include <unordered_map>
#include <ranges>

using namespace std;

int solve(const int &n, const int &k, unordered_map<int, int> &mp, const vector<int> &a) {
    // Check if all frequencies are divisible by k
    for (const auto &[num, freq]: mp) {
        if (freq % k != 0) {
            return 0;
        }
    }

    int response = n;

    for (int len = 2; len <= n / k; ++len) {
        unordered_map<int, int> m;
        int violations = 0; // Track number of elements exceeding limit
        
        // Initialize first window
        for (int i = 0; i < len; ++i) {
            int old_cnt = m[a[i]];
            int limit = mp[a[i]] / k;
            
            // Update violation count
            if (old_cnt == limit) violations++;
            
            m[a[i]]++;
        }

        // Check first window
        if (violations == 0) {
            response++;
        }

        // Slide the window
        for (int r = len; r < n; ++r) {
            int left_val = a[r - len];
            int right_val = a[r];
            int limit_left = mp[left_val] / k;
            int limit_right = mp[right_val] / k;
            
            // Remove left element
            if (m[left_val] == limit_left + 1) violations--;
            m[left_val]--;
            if (m[left_val] == 0) m.erase(left_val);
            
            // Add right element
            if (m[right_val] == limit_right) violations++;
            m[right_val]++;
            
            // Check if current window is valid
            if (violations == 0) {
                response++;
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
        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]]++;
        }

        cout << solve(n, k, mp, a) << "\n";
    }

    return 0;
}
