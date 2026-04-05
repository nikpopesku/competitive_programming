#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(const vector<int> &nums) {

    }
};


int main() {
    auto s = Solution();

    vector<int> v = {1, 0, 2};
    cout << boolalpha << s.isIdealPermutation(v) << '\n';

    vector<int> v2 = {1, 2, 0};
    cout << boolalpha << s.isIdealPermutation(v2) << '\n';
}
