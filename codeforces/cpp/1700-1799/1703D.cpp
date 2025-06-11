#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> vc(n);
    set<string> s;

    for (int i = 0; i < n; ++i)
    {
        cin >> vc[i];
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
            if (s.contains(vc[i].substr(0, j)) and s.contains(vc[i].substr(j)))
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
