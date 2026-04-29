#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {8,1,2,2,3}; const auto e: s.smallerNumbersThanCurrent(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {6,5,4,8}; const auto e: s.smallerNumbersThanCurrent(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {7,7,7,7}; const auto e: s.smallerNumbersThanCurrent(nums)) cout << e << ' ';
    cout << '\n';
}
