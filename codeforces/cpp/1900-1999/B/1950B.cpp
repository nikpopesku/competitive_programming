#include <iostream>

using namespace std;

void solve()
{
    int n, rest;
    cin >> n;
    char elem;

    for (int i = 0; i < 2 * n; ++i)
    {
        if (i / 2 % 2 == 0)
        {
            rest = 0;
        }
        else
        {
            rest = 1;
        }
        for (int j = 0; j < 2 * n; ++j)
        {
            if ((j / 2) % 2 == rest)
            {
                elem = '#';
            }
            else
            {
                elem = '.';
            }

            cout << elem;
        }

        cout << "\n";
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
