#include <iostream>
#include <vector>


int main() {
    std::vector<int> a(5);
    bool possible = false;


    for (int i = 1; i <= 5; i++) {
        std::cin >> a[i];
    }

    if (std::to_string(a[1]) + std::to_string(a[0]) + std::to_string(a[2]) + std::to_string(a[3]) + std::to_string(a[4]) == "12345") {
        std::cout << "Yes\n";
        possible = true;
    }

    if (std::to_string(a[0]) + std::to_string(a[2]) + std::to_string(a[1]) + std::to_string(a[3]) + std::to_string(a[4]) == "12345") {
        std::cout << "Yes\n";
        possible = true;
    }

    if (std::to_string(a[0]) + std::to_string(a[1]) + std::to_string(a[3]) + std::to_string(a[2]) + std::to_string(a[4]) == "12345") {
        std::cout << "Yes\n";
        possible = true;
    }

    if (std::to_string(a[0]) + std::to_string(a[1]) + std::to_string(a[2]) + std::to_string(a[4]) + std::to_string(a[3]) == "12345") {
        std::cout << "Yes\n";
        possible = true;
    }

    if (!possible) std::cout << "No\n";
}