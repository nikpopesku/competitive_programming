#include <iostream>
#include <vector>

#define ll long long

using namespace std;

constexpr ll MD = 1e9 + 7;

class Solution {
public:
    int countGoodNumbers(long long n) {
        return exp(5, n / 2 + (n % 2 == 1 ? 1 : 0)) * exp(4, n / 2) % MD;
    }

private:
    ll exp(ll a, ll p) {
        ll res = 1;
        while (p > 0) {
            if (p % 2 == 1) {
                res = res * a % MD;
                --p;
            } else {
                a = a * a % MD;
                p >>= 1;
            }
        }

        return res;
    }
};

int main() {
    auto s = Solution();

    cout << s.countGoodNumbers(1) << '\n';
    cout << s.countGoodNumbers(4) << '\n';
    cout << s.countGoodNumbers(50) << '\n';
}
