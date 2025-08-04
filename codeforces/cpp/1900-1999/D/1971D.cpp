#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int counter = 0;

    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == '0')
        {
            if (s[i - 1] == '1')
            {
                ++counter;
            }
        }
        else
        {
            if (s[i - 1] == '0')
            {
                ++counter;
            }
        }
    }

    cout << (counter == 0 ? 1 : counter) << "\n";
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
