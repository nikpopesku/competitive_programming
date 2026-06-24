#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean;
        for (const char c : s)
            if (c != '-') clean += toupper(static_cast<unsigned char>(c));

        string result;
        const int first = clean.size() % k;
        if (first) result += clean.substr(0, first);
        for (int i = first; i < static_cast<int>(clean.size()); i += k) {
            if (!result.empty()) result += '-';
            result += clean.substr(i, k);
        }
        return result;
    }
};


int main() {
    auto s = Solution();
    cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << '\n'; //5F3Z-2E9W
    cout << s.licenseKeyFormatting("2-5g-3-J", 2) << '\n'; //2-5G-3J
}
