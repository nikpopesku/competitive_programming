#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define ll long long

ll solve(const int n)
{
    vector<ll> a(n);
    priority_queue<ll> pq;
    set<ll> s;
    ll abs_max = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s.insert(a[i]);

        if (!s.contains(a[i]))
        {
            pq.push(a[i]);
        }
    }

    while (!pq.empty())
    {
        const auto elem = pq.top();
        pq.pop();

        if (elem * (n - 1) * 2 < abs_max) break;

        ll cur_max = 0;

        for (int i = 0; i < n; ++i)
        {
            cur_max += elem ^ a[i];
        }

        abs_max = max(abs_max, cur_max);
    }

    return abs_max;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;


        cout << solve(n) << "\n";
    }
}
