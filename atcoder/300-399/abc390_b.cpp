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

    long long factor = vc[1] / vc[0];

    for (int i = 2; i < n; i++) {
        if (vc[i] / vc[i-1] != factor) {
            response = "No";
            break;
        }
    }

    std::cout << response << std::endl;
}