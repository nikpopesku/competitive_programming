#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector v(101, 0);
        const int n = static_cast<int>(nums.size());
        for (const auto x: nums) ++v[x];
        for (int i = 1; i < 10; ++i) v[i] += v[i - 1];

        vector response(n, 0);
        for (int i = 0; i < n; ++i) {
            response[i] = nums[i] > 0 ? v[nums[i] - 1] : 0;
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {8, 1, 2, 2, 3}; const auto e: s.smallerNumbersThanCurrent(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {6, 5, 4, 8}; const auto e: s.smallerNumbersThanCurrent(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {7, 7, 7, 7}; const auto e: s.smallerNumbersThanCurrent(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {5, 0, 10, 0, 10, 6}; const auto e: s.smallerNumbersThanCurrent(nums)) cout << e << ' ';
    cout << '\n';
}
