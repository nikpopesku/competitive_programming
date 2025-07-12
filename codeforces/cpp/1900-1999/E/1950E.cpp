#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int i = 2;
    vector factors = {1, s.size()};

    while (i <= n / 2 and n > 1)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
        }

        i++;
    }

    ranges::sort(factors);
    factors.erase(ranges::unique(factors).begin(), factors.end());

    for (const auto f:factors)
    {
        int counter = 0;

        for (i = 0; i < s.size();++i)
        {
            if (s[i % f] != s[i])
            {
                ++counter;
            }
        }

        if (f > 1 and counter <= s.size() / f)
        {
            cout << f << "\n";
            break;
        }

        if (f == 1 and counter <= 1)
        {
            cout << "1\n";
            break;
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
