#include "iostream"
#include "vector"

int main() {
    int n, m, q, value1, value2;
    std::cin >> n >> m >> q;
    char type;
    std::vector<std::vector<int>> vc(n);
    vc[0] = std::vector<int>(n);
    for (int i = 0; i < n; i++) vc[0][i] = i;

    for (int i = 0; i < q; i++) {
        std::cin >> type >> value1 >> value2;

        if (type == 'c') {
            if (vc[value1].size() >= value2) {
                std::cout << vc[value1][value2] << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        }

        if (type == 's' and !vc[value1].empty()) {
            vc[value2].push_back(vc[value1].back());
            vc[value1].pop_back();
        }
    }
}