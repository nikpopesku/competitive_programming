#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, value;
    cin >> n;

    int comb1 = 0;
    int comb2 = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> value;

        comb1 ^= value;
        comb2 += value;
    }


    cout << (comb1 == 0 || comb2 % 360 == 0 ? "YES" : "NO") << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
