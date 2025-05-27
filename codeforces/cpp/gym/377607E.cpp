#include "iostream"
#include "vector"

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> phones(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> phones[i];
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
