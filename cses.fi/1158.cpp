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

    vector dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (j - price[i] >= 0) {
                dp[i][j] =
            }
        }
    }

    cout << 1 << "\n";
}