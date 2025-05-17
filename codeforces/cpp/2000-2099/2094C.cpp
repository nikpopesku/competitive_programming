#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;

    while (t--)
    {
        cin >> n;
        vector vc(2 * n, -1);
        vector<int> h(2 * n);
        iota(h.begin(), h.end(), 1);
        set s(h.begin(), h.end());

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> vc[i + j + 1];
                s.erase(vc[i + j + 1]);
            }
        }

        auto it = s.begin();

        for (int i = 0; i < 2 * n; ++i)
        {
            cout << (vc[i] != -1 ? vc[i] : *it) << " ";
            ++it;
        }
        cout << "\n";
    }
}
