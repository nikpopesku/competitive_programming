#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        for (int i = 1; i <= static_cast<int>(nums.size()); ++i) {
            if (i != nums[i]) return {nums[i], i};
        }
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {1, 2, 2, 4}; const auto e: s.findErrorNums(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {1, 1}; const auto e: s.findErrorNums(nums)) cout << e << ' ';
    cout << '\n';
}
