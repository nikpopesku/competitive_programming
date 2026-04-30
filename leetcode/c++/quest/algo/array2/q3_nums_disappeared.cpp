#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector v(n + 1, true);
        for (const auto &x: nums) v[x] = false;

        vector<int> response;

        auto range = views::iota(1, n + 1) | views::filter([&v](const size_t i) { return v[i]; });

        return vector<int>(range.begin(), range.end());
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1}; const auto e: s.findDisappearedNumbers(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {1, 1}; const auto e: s.findDisappearedNumbers(nums)) cout << e << ' ';
    cout << '\n';
}
