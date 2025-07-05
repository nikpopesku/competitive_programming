#include <iostream>
#include <vector>

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

    for (int i = 0; i < n; ++i)
    {
        cin >> intervals[i].start >> intervals[i].end;
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
