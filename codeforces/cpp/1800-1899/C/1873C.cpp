#include <iostream>

using namespace std;

void solve()
{
    string s;
    int response = 0;

    for (int i = 0; i < 10; ++i)
    {
        cin >> s;

        for (int j = 0; j < 10; ++j)
        {
            if (s[j] == 'X')
            {
                if (i == 0 || i == 9 || j == 0 || j == 9) response += 1;
                else if (i == 1 || i == 8 || j == 1 || j == 8) response += 2;
                else if (i == 2 || i == 7 || j == 2 || j == 7) response += 3;
                else if (i == 3 || i == 6 || j == 3 || j == 6) response += 4;
                else if (i == 4 || i == 5 || j == 4 || j == 5) response += 5;
            }
        }
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
