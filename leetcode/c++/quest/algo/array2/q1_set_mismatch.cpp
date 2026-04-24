#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector<bool> val(n + 1, false);
        int duplicate = 0;

        for (int i = 0; i < n; ++i) {
            if (!val[nums[i]]) {
                val[nums[i]] = true;
            } else {
                duplicate = nums[i];
            }
        }

        for (int i = 1; i < n + 1; ++i) {
            if (val[i] == false) {
                return {duplicate, i};
            }
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
