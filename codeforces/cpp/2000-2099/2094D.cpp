#include <iostream>

using namespace std;

string nxt(string k)
{
    string response;
    response += k[0];
    int i = 1;

    while (k[i] == k[0])
    {
        response += k[i];
        ++i;
    }

    return response;
}

string solve(string p, string s)
{
    while (!s.empty() and !p.empty())
    {
        string p0 = nxt(p);
        p = p.substr(p0.size());
        string s0 = nxt(s);
        s = s.substr(s0.size());

        if (s0.size() < p0.size() or s0.size() > p0.size() * 2)
        {
            return "NO";
        }

        if (!p.empty() and s.empty()) return "NO";
        if (!s.empty() and p.empty()) return "NO";
    }

    if (!p.empty() and s.empty()) return "NO";
    if (!s.empty() and p.empty()) return "NO";

    return "YES";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s, p;
        cin >> p;
        cin >> s;

        cout << solve(p, s) << "\n";
    }
}
