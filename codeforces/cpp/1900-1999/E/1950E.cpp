#include <iostream>
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
        const int k = s.size() / f;
        int total_counter_prefix = 0;
        int total_counter_suffix = 0;

        for (int k0 = 0; k0 < k; ++k0)
        {
            int counter_prefix = 0;
            int counter_suffix = 0;

            for (i = 0; i < f;++i)
            {
                if (s[i] != s[k0 * f + i])
                {
                    ++counter_prefix;
                }
                if (s[(k - 1) * f + i] != s[k0 * f + i])
                {
                    ++counter_suffix;
                }
            }

            total_counter_prefix += counter_prefix;
            total_counter_suffix += counter_suffix;
        }

        if (total_counter_prefix <= 1 or total_counter_suffix <= 1)
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
