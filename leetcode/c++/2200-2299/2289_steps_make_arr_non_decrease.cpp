#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int> &nums) {
    }
};


int main() {
    auto s = Solution();

    vector<int> arr = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    cout << s.totalSteps(arr) << endl; // 3

    vector<int> arr2 = {4, 5, 7, 7, 13};
    cout << s.mctFromLeafValues(arr2) << endl; // 0
}
