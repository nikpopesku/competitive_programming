#include <iostream>
#include <ranges>
#include <stack>
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
        stack<int> st_min;
        stack<int> st_max;

        for (int i = 0; i < n; ++i) {
            while (!st_min.empty() && nums[st_min.top()] >= nums[i]) {
                const int index = st_min.top();
                st_min.pop();
                min_right[index] = index - i;
                min_left[index] = st_min.empty() ? index : index - st_min.top();
            }
            st_min.push(i);
        }



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
