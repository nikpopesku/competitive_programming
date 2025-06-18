#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, m, l, r;

    while (t--)
    {
        cin >> n >> m >> l >> r;
        const int l2 = -min(m, -l);
        const int r2 = m + l2;


        cout << l2 << " " << r2 << "\n";
    }
}
