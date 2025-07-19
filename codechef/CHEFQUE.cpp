#include <iostream>
#include <bitset>

using namespace std;

constexpr size_t MAX = 1UL << 31;

int main()
{
    long long q, s1, a, b;
    cin >> q >> s1 >> a >> b;
    unsigned long long s = s1 % MAX;
    unsigned long long sum = 0;
    bitset<MAX> bit(0);

    if (s1 % 2 == 1)
    {
        sum += s1 / 2;
    }

    for (long long i = 2; i <= q; ++i)
    {
        s = (a * s + b) % MAX;

        if (s % 2 == 1 and !bit[1 << (s / 2)])
        {
            bit |= 1 << s;
            sum += s / 2;
        }
        else if (s % 2 == 0 && bit[1 << (s / 2)])
        {
            bit &= ~(1 << s);
            sum -= s / 2;
        }
    }

    cout << sum << "\n";
}
