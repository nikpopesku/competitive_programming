#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, l, r;
    cin >> n >> q;
    vector<long long> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    vector<long long> count(n+1, 0);

    for (int i = 0 ; i < q; ++i)
    {
        cin >> l >> r;

        count[l - 1]++;

        if (r < n)
        {
            --count[r];
        }
    }

    for (int i = 1; i < n; ++i)
    {
        count[i] += count[i-1];
    }

    ranges::sort(a);
    ranges::sort(count.begin(), count.begin() + n);

    long long response  = 0;

    for (int i = 0; i < n; ++i)
    {
        response += a[i] * count[i];
    }

    cout << response << "\n";
}
