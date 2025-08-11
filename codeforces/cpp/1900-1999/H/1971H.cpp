#include <iostream>
#include <vector>


using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector vc(3, vector<int>(n));

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> vc[i][j];
        }
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
