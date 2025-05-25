#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calc(const vector<int>& vc)
{
    int response = 0;
    for (int i = 0; i < vc.size(); ++i) response += i * vc[i];

    cout << response << "\n";
}

void solve()
{
    int q, type, value;
    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        vector<int> vc;
        cin >> type;

        if (type == 2)
        {
            ranges::reverse(vc);
        }
        else if (type == 3)
        {
            cin >> value;
            vc.push_back(value);
        }
        else
        {
            rotate(vc.rbegin(), vc.rbegin() + 1, vc.rend());
        }

        calc(vc);
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
