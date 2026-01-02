#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

    }
};

int main() {
    Solution s;

    cout << s.removeKdigits("1432219", 3) << endl; //aaacecaaa
    cout << s.removeKdigits("10200", 1) << endl; //dcbabcd
    cout << s.removeKdigits("10", 2) << endl; //""

    return 0;
}
