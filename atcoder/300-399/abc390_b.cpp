#include <iostream>
#include <vector>


int main() {
    int n;
    std::cin >> n;
    std::vector<long long> vc(n);
    std::string response = "Yes";

    for (int i = 0; i < n; i++) {
        std::cin >> vc[i];
    }

    for (int i = 1; i < n; i++) {
        if (vc[1] * vc[i - 1] != vc[i] * vc[0]) {
            response = "No";
            break;
        }
    }

    std::cout << response << std::endl;
}