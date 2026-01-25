#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {

    }
};

int main() {
    Solution s;

    vector<int> a = {10, 2};
    cout << s.largestNumber(a) << endl; //210

    vector<int> b = {3, 30, 34, 5, 9};
    cout << s.largestNumber(b) << endl; //9534330

    return 0;
}
