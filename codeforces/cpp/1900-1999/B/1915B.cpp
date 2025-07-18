#include <iostream>
#include <set>

using namespace std;

void solve()
{
    string s;
    string response;

    for (int i = 0; i < 3; ++i)
    {
        set st = {'A', 'B', 'C'};
        cin >> s;
        if (response.empty())
        {
            for (int k = 0; k < 3; ++k)
            {
                st.erase(s[k]);
            }

            if (!st.empty()) response = *st.begin();
        }
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
