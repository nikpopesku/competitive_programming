#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 1) return 0;

        int response = 0;
        vector factor(n, true);

        for (int i = 2; i * i <= n; ++i) {
            if (n % i != 0) continue;
            if (!factor[i]) continue;
            ++response;
            for (int j = i * 2; j * j <= n; j += i) {
                if (n % j == 0) {
                    factor[j] = false;
                }
            }
        }

        return response;
    }
};
int main() {
    auto s = Solution();

    cout << s.countPrimes(10) << '\n'; //4
    cout << s.countPrimes(0) << '\n'; //0
    cout << s.countPrimes(1) << '\n'; //0
}
