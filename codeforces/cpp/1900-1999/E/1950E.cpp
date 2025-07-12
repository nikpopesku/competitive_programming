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
    int sq = static_cast<int>(sqrt(n));
    vector factors = {1, s.size()};

    while (i <= sq and n > 1)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
            sq = static_cast<int>(sqrt(n));
            i = 2;

            continue;
        }

        i++;
    }

    if (n > 1)
    {
        factors.push_back(n);
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

            if (counter > 1) break;
        }

        if (counter <= 1)
        {
            cout << f << "\n";
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
