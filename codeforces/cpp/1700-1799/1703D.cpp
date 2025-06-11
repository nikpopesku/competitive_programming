#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool match(map<int, vector<string>>& mp, const int j, const string& st, set<string>& s)
{
    for (auto& s1 : mp[j])
    {
        if (st.find(s1) == 0 and s.contains(st.substr(st.size() - s1.size(), st.size()))) return true;
    }

    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> vc(n);
    map<int, vector<string>> mp;
    set<string> s;

    for (int i = 0; i < n; ++i)
    {
        cin >> vc[i];
        mp[static_cast<int>(vc[i].size())].push_back(vc[i]);
        s.insert(vc[i]);
    }
    string response;

    for (int i = 0; i < n; ++i)
    {
        if (vc[i].size() == 1)
        {
            response += "0";
            continue;
        }

        bool found = false;

        for (int j = 1; j <= vc[i].size() - 1; ++j)
        {
            if (match(mp, j, vc[i], s))
            {
                found = true;
                break;
            }
        }

        response += (found ? "1" : "0");
    }

    cout << response << "\n";
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
