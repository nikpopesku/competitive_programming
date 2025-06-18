#include <iostream>

using namespace std;

string nxt(const string& k, const int index)
{
    string response;
    response += k[index];
    int i = index + 1;

    while (k[i] == k[index])
    {
        response += k[i];
        ++i;
    }

    return response;
}

string solve(const string& p, const string& s)
{
    int index_p = 0;
    int index_s = 0;

    while (index_p < p.size() and index_s < s.size())
    {
        string p0 = nxt(p, index_p);
        index_p += static_cast<int>(p0.size());
        string s0 = nxt(s, index_s);
        index_s += static_cast<int>(s0.size());

        if (s0[0] != p0[0]) return "NO";
        if (s0.size() < p0.size() or s0.size() > p0.size() * 2) return "NO";
    }

    if (index_p < p.size() and index_s == s.size()) return "NO";
    if (index_s < s.size() and index_p == p.size()) return "NO";

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

        if (s.size() < p.size() or s.size() > 2 * p.size())
        {
            cout << "NO\n";
            continue;
        }

        cout << solve(p, s) << "\n";
    }
}
