#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, value;

    std::cin >> t;

    while (t-- > 0)
    {
        cin >> n;
        vector vc(n + 1, false);

        for (int i = 1; i <= n; ++i)
        {
            cin >> value;
            while (value > n) value /= 2;

            while (vc[value] and value >= 1) value /= 2;

            if (value >= 1 and !vc[value])
            {
                vc[value] = true;
            }
        }

        string response = "YES";

        for (int i = 1; i <= n; ++i)
        {
            if (!vc[i])
            {
                response = "NO";
                break;
            }
        }

        cout << response << "\n";
    }
}
