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
                min_right[index] = i - index;
                min_left[index] = st_min.empty() ? index + 1 : index - st_min.top();
            }

            while (!st_max.empty() && nums[st_max.top()] <= nums[i]) {
                const int index = st_max.top();
                st_max.pop();
                max_right[index] = i - index;
                max_left[index] = st_max.empty() ? index : index - st_max.top();
            }

            st_min.push(i);
            st_max.push(i);
        }

        while (!st_min.empty()) {
            const int index = st_min.top();
            st_min.pop();
            min_right[index] = n - index;
            min_left[index] = st_min.empty() ? index + 1 : index - st_min.top();
        }

        while (!st_max.empty()) {
            const int index = st_max.top();
            st_max.pop();
            max_right[index] = n - index;
            max_left[index] = st_max.empty() ? index : index - st_max.top();
        }


        ll response = 0;

        for (int i = 0; i < n; ++i) {
            // response = response + static_cast<ll>(nums[i]) * (max_left[i] * max_right[i] - min_left[i] * min_right[i]);
            response = response + static_cast<ll>(nums[i]) * min_left[i] * min_right[i];
        }

        return response;
    }
};

int main() {
    Solution s;

    // vector<int> nums = {1, 2, 3};
    // cout << s.subArrayRanges(nums) << '\n';
    //
    // vector<int> nums2 = {4, -2, -3, 4, 1};
    // cout << s.subArrayRanges(nums2) << '\n';

    vector<int> arr1 = {3, 1, 2, 4};
    cout << s.subArrayRanges(arr1) << endl; // Expected: 17

    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << s.subArrayRanges(arr2) << endl; // Expected: 444
    return 0;
}
