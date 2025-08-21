#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int i = 0;
    int response = 0;

    if (s.size() < 2)
    {
        cout << "0\n";
        return;
    }

    while (i <= s.size() - 2)
    {
        if (s[i] == 'A' && s[i + 1] == 'B')
        {
            ++response;
            s[i] = 'B';
            s[i + 1] = 'C';
            i = max(0, i - 1);
            continue;
        }

        if (s[i] == 'B' and s[i + 1] == 'A')
        {
            ++response;
            s[i] = 'C';
            s[i + 1] = 'B';
            ++i;
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
