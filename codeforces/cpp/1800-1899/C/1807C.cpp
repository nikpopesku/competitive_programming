#include <iostream>
#include <unordered_map>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    int next_value = 0;
    bool response = true;

    for (char i : s)
    {
        if (mp.contains(i) and mp[i] != next_value)
        {
            response = false;
            break;
        }

        if (!mp.contains(i))
        {
            mp[i] = next_value;
        }

        next_value = next_value ^ 1;
    }

    cout << (response ? "YES" : "NO") << "\n";
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
