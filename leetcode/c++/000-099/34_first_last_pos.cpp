#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, const int target) {
        const int n = static_cast<int>(nums.size());
        int left = 0, right = n - 1;
        int l = -1, r = -1;

        while (left < right) {
            if (const int m = left + (right - left) / 2; nums[m] < target) {
                left = m + 1;
            } else {
                right = m;
            }
        }

        if (nums[left] == target) {
            l = left;
        } else if (nums[right] == target) {
            l = right;
        }

        return {l, r};
    }
};


int main() {
    auto s = Solution();

    for (const vector<int> st = {5, 7, 7, 8, 8, 10}; auto &e: s.searchRange(st, 8)) {
        for (auto &x: e) cout << x << ' ';
        cout << '\n';
    }
}
