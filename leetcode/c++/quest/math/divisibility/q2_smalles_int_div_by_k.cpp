#include <iostream>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }

        int remainder = 0;

        for (int len = 1; len <= k; ++len) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return len;
            }
        }

        return -1;
    }
};

int main() {
    auto s = Solution();

    cout << s.smallestRepunitDivByK(1) << '\n';
    cout << s.smallestRepunitDivByK(2) << '\n';
    cout << s.smallestRepunitDivByK(3) << '\n';
    cout << s.smallestRepunitDivByK(5) << '\n';
    cout << s.smallestRepunitDivByK(23) << '\n';
}
