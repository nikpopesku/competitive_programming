#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {

    }
};

int main() {
    vector nums = {1, 3, 2, 3, 1};
    auto na = Solution();
    cout << na.reversePairs(nums) << "\n"; //2

    vector nums2 = {2, 4, 3, 5, 1};
    cout << na.reversePairs(nums2) << "\n"; //3
}
