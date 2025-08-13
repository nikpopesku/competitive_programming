#include <iostream>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int response = 0;
    int i = 0;

    while (i < n)
    {
        if (s[i] == 'B')
        {
            ++response;
            i += k;
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
