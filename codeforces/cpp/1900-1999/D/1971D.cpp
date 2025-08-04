#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int res = 1;
    bool ex = false;
    for (int i = 0; i + 1 < static_cast<int>(s.size()); i++)
    {
        res += (s[i] != s[i + 1]);
        ex |= (s[i] == '0' && s[i + 1] == '1');
    }
    cout << res - ex << '\n';
}

int main()
{
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) { solve(); }
}
