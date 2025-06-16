#include <iostream>
using namespace std;

void solve()
{
    int left = 2, right = 99, previous = 99, value;

    while (left < right)
    {
        const int m = left + (right - left + 1) / 2;
        cout << "? " << left << " " << right << endl;
        cin >> value;

        if (value == (right + 1) * left)
        {
            previous = m;
            right = m;
        }
        else if (value == (left + 1) * (right + 1))
        {
            right = left;
            left = 2;
        }
        else
        {
            left = m + 1;
            right = previous;
        }
    }

    cout << "! " << left << endl;
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
