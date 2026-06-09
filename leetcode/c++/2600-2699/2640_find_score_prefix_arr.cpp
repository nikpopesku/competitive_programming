#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int> &nums) {
    }
};

int main() {
    auto sol = Solution();

    // [4,10,24,36,56]
    vector<int> nums{2, 3, 7, 5, 10};
    for (auto &e: sol.findPrefixScore(nums)) {
        cout << e << "\n";
    }
}
