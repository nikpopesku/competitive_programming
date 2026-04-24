#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
    }
};

int main() {
    auto s = Solution();

    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << s.findMaxConsecutiveOnes(nums) << '\n'; //3

    vector<int> nums2 = {1, 0, 1, 1, 0, 1};
    cout << s.findMaxConsecutiveOnes(nums2) << '\n'; //2
}
