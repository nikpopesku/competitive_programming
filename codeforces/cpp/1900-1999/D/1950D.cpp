#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int i = 2;
    string response = "YES";
    vector<int> numbers = {};
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
            numbers.push_back(i);
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
    numbers.push_back(n);

    cout << (numbers.size() == 1 ? "NO" : response) << "\n";
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
