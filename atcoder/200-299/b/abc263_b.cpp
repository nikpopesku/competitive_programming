#include <iostream>

using namespace std;

int main() {
    int n, value, response = 0;
    std::cin >> n;

    for (auto i = 1; i < n; i++) {
        std::cin >> value;

        if (value + 1 == n and response == 0) {
            response = i;
        }
    }

    std::cout << response << std::endl;
}