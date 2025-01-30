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
        } else {
            std::cin >> x >> k;

            if (type == 2) {
                auto it = s.begin();
                while (k > 0) {
                    if (it != s.end()) ++it;
                    --k;
                }

                if (*it <= x) {
                    std::cout << *it << std::endl;
                } else {
                    std::cout << -1 << std::endl;
                }
            }
        }
    }
}