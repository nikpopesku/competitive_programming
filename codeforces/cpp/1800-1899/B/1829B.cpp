#include <iostream>


using namespace std;

void solve()
{
    int n, value;
    cin >> n;
    int max_blank_space = 0, current = 0;;

    for (int i = 0; i < n; ++i)
    {
        cin >> value;

        if (value == 0)
        {
            ++current;
        } else
        {
            max_blank_space = max(max_blank_space, current);
            current = 0;
        }
    }

    max_blank_space = max(max_blank_space, current);

    cout << max_blank_space <<"\n";
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
