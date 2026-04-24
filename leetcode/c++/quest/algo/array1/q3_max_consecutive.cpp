#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int counter = 0;
        int max_counter = 0;

        for (const auto e: nums) {
            if (e == 1) {
                max_counter = max(max_counter, ++counter);
            } else {
                counter = 0;
            }
        }

        return max_counter;
    }
};

int main() {
    auto s = Solution();

    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << s.findMaxConsecutiveOnes(nums) << '\n'; //3

    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    cout << s.findMaxConsecutiveOnes(nums2) << '\n'; //2
}
