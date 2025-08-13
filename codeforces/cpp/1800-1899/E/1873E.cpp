#include <iostream>
#include <vector>

#define ll long long

using namespace std;

// This function checks if a target height 'h' is achievable with 'x' liters of water.
bool is_possible(const ll h, const ll x, const int n, const vector<ll>& a)
{
    ll water_needed = 0;
    for (int i = 0; i < n; ++i)
    {
        if (h > a[i])
        {
            water_needed += (h - a[i]);
        }
        // If water needed already exceeds x, we can stop early.
        if (water_needed > x)
        {
            return false;
        }
    }
    return water_needed <= x;
}

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Binary search for the maximum possible height 'h'.
    // A safe upper bound for h is x (max water) + 10^9 (max coral height).
    ll low = 1, high = 2000000007, ans = 0;

    while (low <= high)
    {
        if (const ll mid = low + (high - low) / 2; is_possible(mid, x, n, a))
        {
            // This height 'mid' is achievable. Let's try for an even higher one.
            ans = mid; // Store this valid answer.
            low = mid + 1; // Move the lower bound up.
        }
        else
        {
            // This height 'mid' is too high. We need to try a lower height.
            high = mid - 1; // Move the upper bound down.
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
