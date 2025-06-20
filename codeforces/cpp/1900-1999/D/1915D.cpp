#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define ll long long

set vowels = {'a', 'e'};
set consonants = {'b', 'c', 'd'};

void solve()
{
    string s;
    int n;
    cin >> n;
    cin >> s;

    string response;

    vector<char> v = {};

    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        v.push_back(*it);
        if (v.size() == 2 and vowels.count(v[0]) and consonants.count(v[1]))
        {
            const string r(v.cbegin(), v.cend());
            response += (!response.empty() ? "." : "") + r;
            v = {};
        }
        if (v.size() == 3 and consonants.count(v[0]) and vowels.count(v[1]) and consonants.count(v[2]))
        {
            const string r(v.cbegin(), v.cend());
            response += (!response.empty() ? "." : "") + r;
            v = {};
        }
    }

    reverse(response.begin(), response.end());

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
