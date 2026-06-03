#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {

    }
};


int main() {
    auto s = Solution();

    vector<int> arr = {6, 2, 4};
    cout << s.mctFromLeafValues(arr) << endl; // 32

    vector<int> arr2 = {4, 11};
    cout << s.mctFromLeafValues(arr2) << endl; // 44
}
