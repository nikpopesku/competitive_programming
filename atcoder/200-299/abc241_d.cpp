#include <iostream>
#include <set>

int main() {
    int q, type, x, k;
    std::cin >> q;
    std::multiset<int> s;

    for (int i = 0; i < q; ++i) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> x;
            s.insert(x);
        }

        if (type == 3) {
            std::cin >> x >> k;
            auto it = s.lower_bound(x);
            it = s.lower_bound(x);

            while (k > 1) {
                if (it == s.end()) break;

                ++it;
                --k;
            }

            std::cout << (it != s.end() ? *it : -1) << std::endl;
        }

        if (type == 2) {
            std::cin >> x >> k;
            auto it = s.lower_bound(x);
            it = s.upper_bound(x);

            while (k > 0) {
                if (it == s.begin()) break;

                --it;
                --k;
            }

            std::cout << (k == 0 ? *it : -1) << std::endl;
        }
    }
}