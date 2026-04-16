#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector prime(n, true);
        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i < n; ++i) {
            if (!prime[i]) continue;
            for (int j = i * 2; j < n; j += i) {
                prime[j] = false;
            }
        }

        return ranges::count(prime, true);
    }
};

int main() {
    auto s = Solution();

    cout << s.countPrimes(10) << '\n'; //4
    cout << s.countPrimes(0) << '\n'; //0
    cout << s.countPrimes(1) << '\n'; //0
    cout << s.countPrimes(2) << '\n'; //0
}
