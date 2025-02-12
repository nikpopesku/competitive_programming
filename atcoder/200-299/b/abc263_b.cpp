#include <iostream>

using namespace std;

int main() {
    unsigned int n, value, response = 0;
    std::cin >> n;

    for (auto i = 1; i <= n; i++) {
        std::cin >> value;

        if (value == n - 1 and response == 0) {
            response = i;
        }
    }

    std::cout << response << std::endl;
}