#include <array>
#include <iostream>

using namespace std::string_literals;

int main() {
    int t;
    std::cin >> t;
    std::array<int, 999999999> primes{};

    for (auto i = 0; i < primes.size(); i++) {
        primes[i] = i;
    }

    for (auto i = 2; i < primes.size(); i++) {
        if (primes[i] == -1) continue;

        const auto number = primes[i] + primes[i];

        while (number < primes.size()) {
            primes[number] = -1;
        }
    }

    for (auto i = 0; i < t; i++) {
        
    }

    return 0;
}
