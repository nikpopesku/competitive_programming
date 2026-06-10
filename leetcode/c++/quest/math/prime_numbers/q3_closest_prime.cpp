#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
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
