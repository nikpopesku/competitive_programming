#include <iostream>
#include <vector>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> vc(n);

    for (int i = 1; i <= n; i++) {
        std::cin >> vc[i - 1];
    }

    long long response = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            response += (vc[i] - vc[j]) * (vc[i] - vc[j]);
        }
    }

    std::cout << response << std::endl;
}