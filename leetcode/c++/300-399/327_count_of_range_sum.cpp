#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
    }
};

int main() {
    auto na = Solution();

    vector v = {-2, 5, -1};
    cout << na.countRangeSum(v, -2, 2) << "\n";

    vector v2 = {0};
    cout << na.countRangeSum(v2, 0, 0) << "\n";
}
