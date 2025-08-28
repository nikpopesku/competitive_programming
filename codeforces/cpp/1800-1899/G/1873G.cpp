#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    bool all = (s[0] == 'B' || s[s.size() - 1] == 'B');

    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == s[i + 1] && s[i] == 'B')
        {
            all = true;
            break;
        }
    }

    int current = 0;
    vector<int> length;

    for (int i = 0; i < s.size() - 1; ++i)
    {
        if (s[i] == 'A')
        {
            ++current;
        }
        else
        {
            if (current > 0)
            {
                length.push_back(current);
            }
        }
    }

    if (current)
    {
        length.push_back(current);
    }

    ranges::sort(length);

    if (length.empty())
    {
        cout << "0\n";
        return;
    }

    int response = 0;
    if (all)
    {
        response += length[0];
    }

    for (int i = 1; i < length.size() - 1; ++i)
    {
        response += length[i];
    }

    cout << response << "\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) { solve(); }
}
