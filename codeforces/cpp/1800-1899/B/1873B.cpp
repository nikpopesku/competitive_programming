#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int response = 1;
    int min_value = 10;
    int value;
    int count_zero = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        min_value = min(min_value, value);
        if (value > 0) response *= value;
        if (value == 0) ++count_zero;
    }

    if (count_zero >= 2)
    {
        cout << "0\n";
        return;
    }

    if (count_zero == 1)
    {
        cout << response << "\n";
        return;
    }

    cout << response / min_value * (min_value + 1) << "\n";
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
