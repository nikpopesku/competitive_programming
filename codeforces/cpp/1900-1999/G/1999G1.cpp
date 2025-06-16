#include <iostream>
using namespace std;

void solve()
{
    int left = 2, right = 999, previous = 999, value;

    while (left < right)
    {

        const int m = left + (right - left) / 2;
        cout << "? " << left << " " << right << endl;
        cin >> value;

        if (value > left * right)
        {
            previous = right;
            right = m;
        }
        else
        {
            left = m;
            right = previous;
        }
    }

    cout << "! " << left << "endl";
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
