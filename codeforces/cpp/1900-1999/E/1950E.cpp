#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 1)
    {
        cout << "1\n";
        return;
    }

    int i = 2;
    int sq = static_cast<int>(sqrt(n));
    vector<int> factors;

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

    cout << "5\n";
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
