#include <iostream>
using namespace std;

void solve()
{
    int left = 1, right = 999, value;

    while (left + 1 < right)
    {
        const int m = left + (right - left + 1) / 2;
        cout << "? " << m << " " << m << endl;
        cin >> value;

        if (value == (m + 1) * (m + 1))
        {
            right = m;
        }
        else
        {
            left = m;
        }
    }

    cout << "! " << right << endl;
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
