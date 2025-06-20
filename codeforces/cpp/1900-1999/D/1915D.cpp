#include <iostream>
#include <set>

using namespace std;

#define ll long long

set<char> vowels = {'a', 'e'};
set<char> consonants = {'b', 'c', 'd'};

string backtrack(const string & s, const int index, string result)
{
    if (index == s.size())
    {
        return result;
    }

    string response1, response2;

    for (int i = index; i < min(static_cast<int>(s.size()), index + 3); ++i)
    {
        if (i - index == 1 and consonants.count(s[index]) and vowels.count(s[i]))
        {
            response1 = backtrack(s, index + 2, result + "." + s[index] + s[i]);
        }
        if (response1.empty() and i - index == 2 and consonants.count(s[index]) and vowels.count(s[i-1]) and consonants.count(s[i]))
        {
            response2 = backtrack(s, index + 3, result + "." + s[index] + s[index + 1] + s[index + 2]);
        }
    }

    if (!response1.empty()) return response1;
    if (!response2.empty()) return response2;

    return "";
}

void solve()
{

    int n;
    cin >> n;
    string s;
    cin >> s;

    cout << backtrack(s, 2, "") << "\n";
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
