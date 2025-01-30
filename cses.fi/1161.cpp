#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> x >> n;
    std::vector<int> vc(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> vc[i];
    }
}