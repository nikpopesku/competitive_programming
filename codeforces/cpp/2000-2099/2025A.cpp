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

        auto response = a.size() - j + b.size();
        if (j > 0) {
            response += 1;
        }
        std::cout<< response << std::endl;
    }

    return 0;
}
