#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 10e9 + 7;

class Solution {
public:
    int createSortedArray(vector<int> &instructions) {
        int response = 0;

        return response % MOD;
    }
};

int main() {
    vector nums = {1, 5, 6, 2};
    auto na = Solution();
    cout << na.createSortedArray(nums) << "\n"; //1

    vector nums2 = {1, 2, 3, 6, 5, 4};
    cout << na.createSortedArray(nums2) << "\n"; //3

    vector nums3 = {1, 3, 3, 3, 2, 4, 2, 1, 2};
    cout << na.createSortedArray(nums3) << "\n"; //4
}
