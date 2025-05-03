#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, d;

    cin >> a >> b;
    cin >> c >> d;
    cout << a * d - b * c << "\n";
}
