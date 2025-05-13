#include <iostream>

using namespace std;

int main()
{
    int t, a, b, c;

    std::cin >> t;

    while (t-- > 0)
    {
        cin >> a >> b >> c;

        if ((c + a) % (2 * b) == 0)
        {
            std::cout << "YES\n";
            continue;
        }
        if ((2 * b - c) % a == 0 and 2 * b != c)
        {
            std::cout << "YES\n";
            continue;
        }
        if ((2 * b - a) % c == 0 and 2 * b != a)
        {
            std::cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}
