#include <iostream>
#include <vector>

using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> vc[i];
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
