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
        int total_counter = 0;

        for (int k0 = 0; k0 < k; ++k0)
        {
            int counter = 0;

            for (i = 0; i < f;++i)
            {
                if (s[i] != s[k0 * f + i])
                {
                    ++counter;
                }
            }

            total_counter += counter;

            if (counter > 1 or total_counter > 1)
            {
                break;
            }
        }

        if (total_counter <= 1)
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
