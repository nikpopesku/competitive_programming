#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

ll solve(const int n)
{
    vector<ll> a(n);
    priority_queue<ll> pq;
    ll abs_max = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        pq.push(a[i]);
    }

    while (!pq.empty())
    {
        const auto elem = pq.top();
        pq.pop();

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
