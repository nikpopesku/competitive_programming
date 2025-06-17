#include <iostream>
using namespace std;

void solve()
{
    int left = 1, right = 999, value;

    while (left + 2 < right)
    {
        const int delta = (right - left) / 3;
        const int new_left = left + delta;
        const int new_right = right - delta;
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

    if (right - left == 2)
    {
        cout << "? 1 " << left + 1 << endl;
        cin >> value;

        if (value != left + 1) { right = left + 1; }
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
