#include <iostream>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

    }
};


int main() {
    auto s = Solution();
    cout <<  s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << '\n'; //5F3Z-2E9W
    cout <<  s.licenseKeyFormatting("2-5g-3-J", 2) << '\n'; //2-5G-3J
}
