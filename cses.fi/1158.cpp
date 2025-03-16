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
        for (int i = 0; i <= x; ++i) {
            if ((i == 0 or dp[i] > 0) and price[j] + i <= x and dp[i] + pages[j] > dp[i + price[j]]) {
                dp[i + price[j]] = dp[i] + pages[j];
            }
        }
    }

    cout << dp[x] << "\n";
}