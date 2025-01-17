#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;
    std::string s = std::to_string(n);
    long long max_l = (s.size() / 2) * 2;
    long long response = 0;

    for (auto i = 2; i <= max_l; i += 2) {
        long long number = 0;
        int counter = 0;

        while (counter < i) {
            number = number * 10 + 9;
            counter++;
        }

        if (number < n) {
            response += (9 * std::pow(10, i / 2 - 1));
        } else {
            long long pw = std::pow(10, i / 2);
            long long left = n / pw;
            long long right = n % pw;
            if (std::min(left, right) >= std::pow(10, i / 2 - 1)) {
                response += std::min(left, right) - std::pow(10, i / 2 - 1) + 1;
            }
        }
    }

    std::cout << response << std::endl;
}