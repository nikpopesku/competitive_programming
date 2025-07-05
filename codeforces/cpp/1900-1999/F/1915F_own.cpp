#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
};

void solve()
{
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    vector<int> endpoints(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i].start >> intervals[i].end;
        endpoints[i] = intervals[i].end;
    }

    ranges::sort(endpoints);
    endpoints.erase(ranges::sort(endpoints.begin(), endpoints.end()));
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
