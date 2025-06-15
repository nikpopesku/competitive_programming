#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_profit = 0;
    long long current_profit = 0;

    for (int i = 0; i < n; ++i) {
        // At each step i, we decide what is the maximum profit we can get
        // from the subarray a[i...n-1].

        long long spell_profit = 0;
        // Calculate profit if we use the spell starting from chest i
        for (int j = i; j < n; ++j) {
            // The value of chest j is halved (j - i + 1) times
            // A lookahead of 31 is sufficient since 2^31 > 10^9
            if (j - i > 31) {
                break;
            }
            spell_profit += a[j] >> (j - i + 1);
        }

        // The total profit up to this point is current_profit.
        // We can either stop here and take current_profit,
        // or we can add the spell_profit from this point onwards.
        max_profit = max(max_profit, current_profit + spell_profit);

        // Now, update current_profit for the next iteration by assuming
        // we pay the key for the current chest.
        current_profit += a[i] - k;
    }

    // Final check: maybe the best option was to take some chests normally
    // and then just stop without using the spell.
    max_profit = max(max_profit, current_profit);


    cout << max_profit << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
