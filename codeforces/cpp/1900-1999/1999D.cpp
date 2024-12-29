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
        std::string response {};

        while (index_source < s.size()) {
            if (index_target < t.size() and (s[index_source] == t[index_target] or s[index_source] == '?')) {
                response += t[index_target];
                index_target++;
                index_source++;
            } else if (index_target == t.size() and s[index_source] == '?') {
                response += 'a';
                index_source++;
            } else {
                response += s[index_source];
                index_source++;
            }
        }

        if (index_target == t.size()) {
            std::cout << "YES" << std::endl;
            std::cout << response << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}
