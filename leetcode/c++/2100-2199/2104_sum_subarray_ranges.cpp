#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector min_left(n, 1);
        vector min_right(n, 1);
        vector max_left(n, 1);
        vector max_right(n, 1);

        ll response = 0;

        for (int i = 0; i < n; ++i) {
            response = response + static_cast<ll>(nums[i]) * (max_left[i] * max_right[i] - min_left[i] * min_right[i]);
        }

        return response;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 3};
    cout << s.subArrayRanges(nums) << '\n';

    return 0;
}
