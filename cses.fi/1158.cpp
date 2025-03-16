#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> price(n, 0);
    vector<int> pages(n, 0);
    for (int i = 0; i < n; ++i) cin >> price[i];
    for (int i = 0; i < n; ++i) cin >> pages[i];

    vector<int> dp(x + 1, 0);

    for (int j = 0; j < n; ++j) {
        for (int i = 1; i <= x; ++i) {
            if (dp[i] > 0 and price[j] + i <= x and dp[i] + pages[j] > dp[i + price[j]]) {
                dp[i + price[j]] = dp[i] + pages[j];
            }
        }
        if (price[j] <= x and dp[0] + pages[j] > dp[price[j]]) dp[price[j]] = dp[0] + pages[j];
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
}