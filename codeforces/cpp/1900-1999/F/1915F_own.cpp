#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
};

class Fenwick
{
public:
    explicit Fenwick(const int n): n(n)
    {
        bit.assign(n, 0);
    }

    void update(int i, const int delta)
    {
        while (i < n)
        {
            bit[i] += delta;

            i = i | i + 1;
        }
    }

    [[nodiscard]] int query(int i) const
    {
        int response = 0;

        while (i >= 0)
        {
            response += bit[i];

            i = (i & i + 1) - 1;
        }

        return response;
    }

private:
    int n = 0;
    vector<int> bit;
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
    endpoints.erase(ranges::unique(endpoints).begin(), endpoints.end());

    for (auto& [start, end] : intervals)
    {
        end = ranges::lower_bound(endpoints, end) - endpoints.begin();
    }

    ranges::sort(intervals, [](const Interval& a, const Interval& b)
    {
        if (a.start != b.start)
        {
            return a.start < b.start;
        }

        return a.end > b.end;
    });

    auto fn = Fenwick(n);
    long long inversions = 0;

    for (int i = 0; i < n; ++i)
    {
        inversions += fn.query(n - 1) - fn.query(intervals[i].end - 1);
        fn.update(intervals[i].end, 1);
    }

    cout << inversions << "\n";
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
