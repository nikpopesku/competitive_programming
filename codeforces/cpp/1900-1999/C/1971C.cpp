#include <iostream>
#include <set>

using namespace std;

void solve()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    bool condition = false;
    set<int> s1, s2;

    for (int i = 1; i <= 12; ++i)
    {
        if (i != a && i != b)
        {
            if (condition)
            {
                s1.insert(i);
            }
            else
            {
                s2.insert(i);
            }
        }
        else
        {
            condition = !condition;
        }
    }

    cout << ((s1.contains(c) && s2.contains(d)) || (s1.contains(d) && s2.contains(c)) ? "YES\n" : "NO\n");
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
