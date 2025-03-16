#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> prices(n + 1, 0);
    vector<int> pages(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> prices[i];
    for (int i = 1; i <= n; ++i) cin >> pages[i];

    vector dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int price = 0; price <= x; ++price) {
            if (price - prices[i] >= 0) {
                dp[i][price] = max(dp[i][price - prices[i]] + pages[i], dp[i - 1][price]);
            }
        }
    }

    cout << dp[n][x] << "\n";
}