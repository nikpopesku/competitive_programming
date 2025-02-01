#include <iostream>
#include <set>

int main() {
    int t, value;
    std::cin >> t;


    for (auto i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::multiset<int> s, s_copy;

        for (int j = 0; j < 2 * n; ++j) {
            std::cin >> value;
            s.insert(value);
        }

        auto it = s.begin();
        auto last = --s.end();
        std::string response = "NO";

        while (it != last and response == "NO") {
            s_copy = s;
            auto last_copy = --s_copy.end();
            int max_value = *last_copy + *it;

            while (!s_copy.empty()) {
                auto itt = s_copy.find(max_value - *last_copy);
                if (itt == s_copy.end()) break;
                s_copy.erase(itt);
                if (s_copy.count(max_value - *last_copy) == 0 or s_copy.count(*last_copy) == 1) {
                    max_value = *last_copy;
                }
                s_copy.erase(last_copy);
                last_copy = s_copy.end();
                if (s_copy.size() > 0) {
                    --last_copy;
                }
            }

            if (s_copy.empty()) response = "YES";

            ++it;
        }

        std::cout << response << std::endl;
    }
}
