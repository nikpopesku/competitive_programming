#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    long long n, value;
    cin >> n;
    set<long long> keys, values;

    for (long long i = 1; i <= n; ++i)
    {
        cin >> value;
        if (value < i)
        {
            keys.insert(i);
            values.insert(value);
        }
    }

    auto it_keys = keys.crbegin();
    auto it_values = values.crbegin();
    long long response = 0;
    long long counter = 0;

    while (it_keys != keys.crend() and it_values != values.crend())
    {
        if (*it_values > *it_keys)
        {
            ++counter;
            ++it_values;
        }
        else
        {
            response += counter;
            ++it_keys;
        }
    }

    while (it_keys != keys.crend())
    {
        response += counter;
        ++it_keys;
    }

    cout << response << "\n";
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
