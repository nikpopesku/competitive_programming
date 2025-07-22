#include <iostream>
#include <bitset>
#include <cstdint>

using namespace std;


int main()
{
    constexpr uint64_t MAX = 1ULL << 32;

    long long q, s1, a, b;
    cin >> q >> s1 >> a >> b;
    uint64_t s = s1 % MAX;
    uint64_t sum = 0;
    bitset<MAX> bit(0);

    if (s1 % 2 == 1)
    {
        sum += s1 / 2;
    }

    for (long long i = 2; i <= q; ++i)
    {
        s = (a * s + b) % MAX;

        if (s % 2 == 1 and !bit[s / 2])
        {
            bit[s / 2] = true;
            sum += s / 2;
        }
        else if (s % 2 == 0 && bit[s / 2])
        {
            bit[s / 2] = false;
            sum -= s / 2;
        }
    }

    cout << sum << "\n";
}
