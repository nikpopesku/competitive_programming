#include <iostream>

int main() {
    int tt;
    std::string s, t;
    std::cin >> tt;


    for (auto i = 0; i < tt; i++) {
        std::cin >> s;
        std::cin >> t;

        int index_source = 0;
        int index_target = 0;

        while (index_target < t.size() and index_source < s.size()) {
            if (s[index_source] == t[index_target] or s[index_source] == '?') {
                index_target++;
                index_source++;
            } else {
                index_source++;
            }
        }

        std::cout << (index_target == t.size() ? "YES" : "NO") << std::endl;
    }
}
