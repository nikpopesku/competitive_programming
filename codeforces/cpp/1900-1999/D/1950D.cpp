#include <iostream>
#include <math.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int i = 1;
    string response = "YES\n";

    while (i <= static_cast<int>(sqrt(n)))
    {
        if (n % i == 0)
        {
            string s = static_cast<string>(i);
            for (int j = 0; s.size(); ++j)
            {
                if (s[i] >= '2')
                {
                    response = "NO\n";
                    break;
                }
            }

            n /= i;
            i = 1;
            continue;
        }

        ++i;
    }

    cout << response;
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
