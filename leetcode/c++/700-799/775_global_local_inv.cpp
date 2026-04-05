#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {

    }
};


int main() {
    auto s = Solution();

    vector<int> v = {1,0,2};
    cout << s.isIdealPermutation(v) << ' ';

    vector<int> v2 = {1,2,0};
    cout << s.isIdealPermutation(v2) << ' ';

}
