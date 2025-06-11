#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector vc(n, vector<int>(n));
    string s;

    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        for (int j = 0; j < n; ++j)
        {
            vc[i][j] = s[j] == '1' ? 1 : 0;
        }
    }

    const int k = n / 2;
    int response = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            int s = vc[i][j] + vc[i + k][j] + vc[i + k][j + k] + vc[i][j + k];

            if (s == 1 or s == 3)
            {
                response += 1;
            }
            else if (s == 2)
            {
                response += 2;
            }
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
