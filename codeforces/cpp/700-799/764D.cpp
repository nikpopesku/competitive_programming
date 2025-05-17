#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, n, k;
    string s;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cin >> s;
        unordered_map<char, int> mp;

        for (auto& c : s) mp[c]++;
        int pairs = 0;
        int odd = 0;

        for (const auto& elem : mp)
        {
            pairs += elem.second / 2;
            if (elem.second % 2 == 1)
            {
                odd += 1;
            }
        }

        int response = pairs / k * 2;
        response += (pairs % k + odd) / k;

        cout << response << "\n";
    }
}
