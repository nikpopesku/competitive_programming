#include <iostream>
using namespace std;

void solve()
{
    int left = 1, right = 999, value;

    while (left + 1 < right)
    {
        const int m = left + (right - left + 1) / 2;
        const int new_left = left + (m - left) / 2;
        const int new_right = m + (right - m) / 2;
        cout << "? " << new_left << " " << new_right << endl;
        cin >> value;
        if (value == -1) return;

        if (value == new_left * new_right)
        {
            left = new_right;
        }
        else if (value == (new_left + 1) * (new_right + 1))
        {
            left = new_left;
        }
        else
        {
            left = new_left;
            right = new_right;
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
