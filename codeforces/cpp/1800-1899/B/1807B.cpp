#include <iostream>
#include <queue>

using namespace std;

void solve()
{
    int n, value;
    cin >> n;
    int even_sum = 0, odd_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> value;

        if (value % 2 == 1)
        {
            odd_sum += value;
        }
        else
        {
            even_sum += value;
        }
    }

    if (even_sum > odd_sum)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
