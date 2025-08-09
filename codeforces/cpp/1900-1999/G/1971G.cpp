#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), response(n);
    int group_counter = 0;
    vector<set<int>> positions;
    vector<multiset<int>> values;
    map<int, int> mp;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (!mp.contains(a[i]))
        {
            int value = a[i];
            mp[value] = group_counter;
            value = value >> 2;
            value = value << 2;

            mp[value] = group_counter;
            mp[value + 1] = group_counter;
            mp[value + 2] = group_counter;
            mp[value + 3] = group_counter;
            ++group_counter;
        }

        positions[mp[a[i]]].insert(i);
        values[mp[a[i]]].insert(a[i]);
    }

    for (int i = 0; i < group_counter; ++i)
    {
        auto it_values = values[i].begin();
        auto it_positions = positions[i].begin();

        while (it_values != values[i].end())
        {
            response[*it_positions] = *it_values;
            ++it_values;
            ++it_positions;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << response[i] << " ";
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
