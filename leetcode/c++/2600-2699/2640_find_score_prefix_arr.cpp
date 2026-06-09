#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int> &nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> max_val = nums;

        for (int i = 0; i < n; ++i) {

        }
    }
};

int main() {
    auto sol = Solution();

    // [4,10,24,36,56]
    for (vector<int> nums{2, 3, 7, 5, 10}; const auto &e: sol.findPrefixScore(nums)) {
        cout << e << "\n";
    }
    // [2,4,8,16,32,64]
    for (vector<int> nums{1, 1, 2, 4, 8, 16}; const auto &e: sol.findPrefixScore(nums)) {
        cout << e << "\n";
    }
}
