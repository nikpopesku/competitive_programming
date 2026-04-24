#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {1, 2, 2, 4}; const auto e: s.findErrorNums(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {1, 1}; const auto e: s.findErrorNums(nums)) cout << e << ' ';
    cout << '\n';
}
