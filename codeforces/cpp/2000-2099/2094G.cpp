#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void calc(const multimap<int, int>& mp)
{
    int response = 0;
    for (const auto& [fst, snd] : mp) response += fst * (snd + 1);

    cout << response << "\n";
}

void solve()
{
    int q, type, value;
    multimap<int, int> mp;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> type;

        if (type == 2)
        {
            for (auto& e : mp)
            {
                e.second = static_cast<int>(mp.size()) - e.second - 1;
            }
        }
        else if (type == 3)
        {
            cin >> value;
            mp.insert({value, mp.size()});
        }
        else
        {
            for (auto& e : mp)
            {
                e.second = (e.second + 1) % static_cast<int>(mp.size());
            }
        }

        calc(mp);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}
