#include <iostream>


using namespace std;

void solve()
{
    string t;
    cin >> t;
    const string s = "codeforces";
    int counter = 0;

    for (int i = 0; i < 10; ++i)
    {
        if (s[i] != t[i]) ++counter;
    }

    cout << counter << "\n";
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
