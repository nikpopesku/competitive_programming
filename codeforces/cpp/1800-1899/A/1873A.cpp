#include <iostream>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int counter = 0;

    if (s[0] != 'a') ++counter;
    if (s[1] != 'b') ++counter;
    if (s[2] != 'c') ++counter;

    cout << (counter <= 2 ? "YES" : "NO") << "\n";
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
