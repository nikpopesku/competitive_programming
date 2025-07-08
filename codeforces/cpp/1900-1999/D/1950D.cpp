#include <iostream>
#include <math.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int i = 2;
    string response = "YES";
    for (const char j : to_string(n))
    {
        if (j - '0' > 1)
        {
            response = "NO";

            break;
        }
    }

    if (response == "YES")
    {
        cout << response << "\n";

        return;
    }

    response = "YES";

    while (i <= static_cast<int>(sqrt(n)))
    {
        if (n % i == 0)
        {
            string s = to_string(i);
            for (const char j : s)
            {
                if (j - '0' > 1)
                {
                    response = "NO";
                    break;
                }
            }

            n /= i;
            i = 2;
            continue;
        }

        ++i;
    }

    cout << response << "\n";
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
