#include <array>
#include <iostream>
#include <vector>

std::vector<std::string> get_numbers(const std::string& number, const int start, const int left) {
    std::vector<std::string> response {};

    for (int i = start; i < number.size() - left; i++) {
        const char value = number[i];

        if (left > 0) {
            for (auto &val: get_numbers(number, i+1, left - 1)) {
                response.push_back(value + val);
            }
        }
    }

    return response;
}

int main() {
    int t;
    std::cin >> t;
    std::array<int, 9999> primes{};

    for (auto i = 0; i < primes.size(); i++) {
        primes[i] = i;
    }

    for (auto i = 2; i < primes.size(); i++) {
        if (primes[i] == -1) continue;

        auto number = primes[i] + primes[i];

        while (number < primes.size()) {
            primes[number] = -1;
            number = primes[i];
        }
    }

    // for (auto i = 0; i < t; i++) {
    //     std::string number;
    //     std::cin >> number;
    //     std::vector<int> numbers {};
    //
    //     for (int left = 2; left < 10; left++) {
    //         for (auto start = 0; start < 9 - left; start++) {
    //             for (auto &elem: get_numbers(number, start, left)) {
    //                 numbers.push_back(std::stoi(elem));
    //             }
    //         }
    //     }
    //
    //     for (auto &elem: numbers) {
    //         if (primes[elem] != -1) {
    //             puts(reinterpret_cast<const char *>(static_cast<char>(elem)));
    //         }
    //     }
    // }

    return 0;
}
