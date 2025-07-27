#include <iostream>
#include <set>

using namespace std;

void solve()
{
    int n, minutes;
    cin >> n;
    string s;
    int min1 = 2 * 1e5;
    int min2 = 2 * 1e5;
    int min_common = 2 * 1e5;
    set<int> book1, book2;


    for (int i = 0; i < n; ++i)
    {
        cin >> minutes >> s;

        if (s == "11")
        {
            min_common = min(min_common, minutes);
        }
        else if (s[0] == '1')
        {
            if (minutes < min1)
            {
                min1 = minutes;
                book1 = {i};
            }
            else if (minutes == min1)
            {
                book1.insert(i);
            }
        }
        else if (s[1] == '1')
        {
            if (minutes < min2)
            {
                min2 = minutes;
                book2 = {i};
            }
            else if (minutes == min2)
            {
                book2.insert(i);
            }
        }
    }

    for (auto elem : book1)
    {
        if (book2.contains(elem))
        {
            cout << min1 << "\n";
            return;
        }
    }

    if ((min1 < 2 * 1e5 && min2 < 2 * 1e5) || min_common < 2 * 1e5)
    {
        cout << (min1 + min2 < min_common ? min1 + min2 : min_common) << "\n";
    }
    else
    {
        cout << "-1\n";
    }
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
