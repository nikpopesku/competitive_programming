#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> genres(n);
    vector<string> writers(n);


    for (int i = 0; i < n; ++i)
    {
        cin >> genres[i] >> writers[i];
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
