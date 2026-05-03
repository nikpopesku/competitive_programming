#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73}; const auto e: s.dailyTemperatures(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {30, 40, 50, 60}; const auto e: s.dailyTemperatures(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {30, 60, 90}; const auto e: s.dailyTemperatures(nums)) cout << e << ' ';
    cout << '\n';
}
