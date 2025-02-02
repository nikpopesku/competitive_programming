#include <iostream>
#include <vector>
#include <set>

int main() {
    int t, value;
    std::cin >> t;


    for (auto i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::multiset<int> s, s_copy;
        std::vector<int> pairs;

        for (int j = 0; j < 2 * n; ++j) {
            std::cin >> value;
            s.insert(value);
        }

        auto it = s.begin();
        auto last = --s.end();
        std::string response = "NO";

        while (it != last and response == "NO") {
            pairs = {};
            s_copy = s;
            auto last_copy = --s_copy.end();
            int max_value = *last_copy + *it;

            while (!s_copy.empty()) {
                auto itt = s_copy.find(max_value - *last_copy);
                if (itt == s_copy.end() or itt == last_copy) break;
                pairs.push_back(*itt);
                s_copy.erase(itt);
                if (s_copy.count(max_value - *last_copy) == 0 or s_copy.count(*last_copy) == 1) {
                    max_value = *last_copy;
                }
                pairs.push_back(*last_copy);
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
        if (response == "YES") {
            std::cout << pairs[0] + pairs[1] << std::endl;

            for (int j = 0; j < pairs.size(); ++j) {
                std::cout << pairs[j];

                if (j % 2 == 1) {
                    std::cout << std::endl;
                } else {
                    std::cout << ' ';
                }
            }
        }
    }
}
