#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        const int n = static_cast<int>(s.size());
        string current_group;
        string formatted_key;

        for (int i = n; i >= 0; --i) {
            if (s[i] == '-') continue;
            if (current_group.size() == k) {
                formatted_key = current_group + (formatted_key.size() > 0 ? "-" : "");
                current_group = "";
            }

            current_group = to_string(toupper(s[i])) + current_group;
        }

        formatted_key = current_group + (formatted_key.size() > 0 ? "-" : "");

        return formatted_key;
    }
};


int main() {
    auto s = Solution();
    cout <<  s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << '\n'; //5F3Z-2E9W
    cout <<  s.licenseKeyFormatting("2-5g-3-J", 2) << '\n'; //2-5G-3J
}
