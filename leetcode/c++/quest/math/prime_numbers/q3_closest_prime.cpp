#include <iostream>
#include <vector>

using namespace std;

constexpr int MX = 1e6;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        bool v[MX] = {true};

        for (int i = 2; i <= right; ++i) {
            if (v[i] == false) continue;
            int j = i;

            while (j * j <= right) {
                v[j] = false;
                j += i;
            }
        }
    }
};

int main() {
    auto s = Solution();

    for (const auto &x: s.closestPrimes(10, 19)) {
        cout << x << ' '; //[11,13]
    }
    cout << '\n';

    for (const auto &x: s.closestPrimes(4, 6)) {
        cout << x << ' '; //[-1,-1]
    }
    cout << '\n';
}
