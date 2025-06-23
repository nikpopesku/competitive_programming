#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), partial_sum_even(n+1, 0), partial_sum_odd(n+1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i > 0 and i % 2 == 1) {
            partial_sum_odd[i] = partial_sum_odd[i-1] + v[i];
            partial_sum_even[i] = partial_sum_even[i-1];
        } else if (i > 0) {
            partial_sum_odd[i] = partial_sum_odd[i-1];
            partial_sum_even[i] = partial_sum_even[i-1] + v[i];
        }
    }

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
