#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int trap(const vector<int> &height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int response = 0;
        int possible_max = 0;

        while (left < right) {
            possible_max = max(possible_max, min(height[left], height[right]));

            if (height[left] < height[right]) {
                if (possible_max > height[left]) {
                    response += possible_max - height[left];
                }
                ++left;
            } else {
                if (possible_max > height[right]) {
                    response += possible_max - height[right];
                }
                --right;
            }
        }

        return response;
    }
};


int main() {
    auto s = Solution();

    vector nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(nums) << endl; //6

    vector nums2 = {4, 2, 0, 3, 2, 5};
    cout << s.trap(nums2) << endl;
}
