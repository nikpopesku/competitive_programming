#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

constexpr long long MAX = pow(2, 32);

int main()
{
    long long q, s1, a, b;
    cin >> q >> s1 >> a >> b;
    long long s = s1 % MAX;

    bitset<MAX> bit;

    if (s1 % 2 == 1)
    {
        bit |= 1 << s1;
    }
    else
    {
        bit &= ~(1 << s1);
    }

    for (long long i = 2; i <= q; ++i)
    {
        s = (a * s + b) % MAX;

        if (s % 2 == 1)
        {
            bit |= 1 << s;
        }
        else
        {
            bit &= ~(1 << s);
        }
    }

    long long sum = 0;

    for (long long i  = 0; i < MAX; ++i)
    {
        if (bit & 1 << i) sum += i;
    }

    cout << sum << "\n";
}
