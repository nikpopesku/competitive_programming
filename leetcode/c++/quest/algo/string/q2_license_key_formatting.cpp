#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        const int n = static_cast<int>(s.size());
        string current_group;
        string formatted_key;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '-') continue;
            if (current_group.size() == k) {
                formatted_key.insert(0, current_group + (!formatted_key.empty() ? "-" : ""));
                current_group = "";
            }

            current_group.insert(0, 1, static_cast<char>(toupper(static_cast<unsigned char>(s[i]))));
        }

        if (!current_group.empty()) {
            formatted_key.insert(0, current_group + (!formatted_key.empty() ? "-" : ""));
        }

        return formatted_key;
    }
};


int main() {
    auto s = Solution();
    cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << '\n'; //5F3Z-2E9W
    cout << s.licenseKeyFormatting("2-5g-3-J", 2) << '\n'; //2-5G-3J
}
