#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {8, 4, 6, 2, 3}; const auto e: s.finalPrices(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {1, 2, 3, 4, 5}; const auto e: s.finalPrices(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {10, 1, 1, 6}; const auto e: s.finalPrices(nums)) cout << e << ' ';
    cout << '\n';
}
