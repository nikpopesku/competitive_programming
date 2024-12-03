#include <iostream>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    for (auto i = 0; i < q; i++) {
        std::string a, b;
        std::cin>>a>>b;

        int j = 0;
        while (j < a.size() and j < b.size()) {
            if (a[j] != b[j]) break;
            j++;
        }

        const auto response = a.size() - j + b.size() - j + 1 + j;
        std::cout<< response << std::endl;
    }

    return 0;
}
