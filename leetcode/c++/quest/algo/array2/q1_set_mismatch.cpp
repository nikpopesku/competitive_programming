#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i + 1 != nums[i]) return {nums[i], i + 1};
        }

        return nums;
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {1, 2, 2, 4}; const auto e: s.findErrorNums(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {1, 1}; const auto e: s.findErrorNums(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {3, 2, 2}; const auto e: s.findErrorNums(nums)) cout << e << ' ';
    cout << '\n';
}
