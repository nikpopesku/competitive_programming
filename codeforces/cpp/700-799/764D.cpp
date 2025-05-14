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

        int counter = 0;

        for (const auto& it : ch)
        {
            if (it.second % 2 == 1) ++counter;
        }

        int base = (s.size() - counter) / 2;
        if (base % 2 != 0) --base;


        int additional = k <= counter ? 1 : 0;
        cout << base + additional << "\n";
    }
}
