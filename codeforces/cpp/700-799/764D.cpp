#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int t, n, k;
    string s;

    std::cin >> t;

    while (t-- > 0)
    {
        cin >> n >> k;
        cin >> s;

        unordered_map<char, int> ch;

        for (char i : s) ch[i]++;

        int counter_odd = 0;

        for (const auto& it : ch)
        {
            if (it.second % 2 == 1) ++counter_odd;
        }

        int counter_even = s.size() - counter_odd;
        int base = counter_even / 2;
        if (base % 2 != 0) --base;


        int additional = k <= counter_odd ? 1 : 0;
        if (counter_even / 2 % 2 == 1 and counter_odd < k) ++additional;
        cout << base + additional << "\n";
    }
}
