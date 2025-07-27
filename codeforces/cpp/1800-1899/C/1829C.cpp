#include <iostream>
#include <set>

using namespace std;

void solve()
{
    int n, minutes;
    cin >> n;
    string s;
    int min1 = 2 * 1e5;
    int min2 = 2 * 1e5;
    int min_common = 4 * 1e5;


    for (int i = 0; i < n; ++i)
    {
        cin >> minutes >> s;

        if (s == "11") min_common = min(min_common, minutes);
        if (s[0] == '1') min1 = min(min1, minutes);
        if (s[1] == '1') min2 = min(min2, minutes);
    }


    if (min1 < 2 * 1e5 && min2 < 2 * 1e5)
    {
        cout << min(min1 + min2, min_common) << "\n";
    }
    else
    {
        cout << "-1\n";
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
