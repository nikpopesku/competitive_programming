#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve()
{
    int q, type, value, response = 0;
    multimap<int, int> mp;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> type;

        if (type == 2)
        {
            for (auto& [fst, snd] : mp)
            {
                const int previous = snd;
                snd = static_cast<int>(mp.size()) - snd - 1;
                response += (snd - previous) * fst;
            }
        }
        else if (type == 3)
        {
            cin >> value;
            mp.insert({value, mp.size()});
            response += value * static_cast<int>(mp.size());
        }
        else
        {
            for (auto& [fst, snd] : mp)
            {
                const int previous = snd;
                snd = (snd + 1) % static_cast<int>(mp.size());
                response += (snd - previous) * fst;
            }
        }

        cout << response << "\n";
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
