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
        auto last = s.end();
        last--;
        auto last_copy = last;

        while (it != last) {
            s_copy = s;
            last_copy = last;

            while (!s_copy.empty()) {
                int max_value =
            }

            ++it;
            last = s.end();
        }
    }
}
