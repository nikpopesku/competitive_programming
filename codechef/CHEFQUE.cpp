#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

constexpr long long MAX = static_cast<long long>(pow(2, 32));

int main()
{
    long long q, s1, a, b;
    cin >> q >> s1 >> a >> b;
    long long s = s1 % MAX;
    long long sum = 0;
    bitset<MAX> bit;

    if (s1 % 2 == 1)
    {
        sum += s1 / 2;
    }

    for (long long i = 2; i <= q; ++i)
    {
        s = (a * s + b) % MAX;

        if (s % 2 == 1 && bit ^ 1 << (s / 2))
        {
            bit |= 1 << s;
            sum += s / 2;
        }
        else if (s % 2 == 0 && bit & 1 << (s / 2))
        {
            bit &= ~(1 << s);
            sum -= s / 2;
        }
    }


    // for (long long i = 0; i < MAX; ++i)
    // {
    //     if (bit & 1 << i) sum += i;
    // }

    cout << sum << "\n";
}
