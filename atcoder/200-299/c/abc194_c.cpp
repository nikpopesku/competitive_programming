#include <iostream>
#include <vector>


int main() {
    long long n;
    std::cin >> n;
    std::vector<long long> vc(n);
    long long response = 0;
    long long partial_sum = 0;

    for (auto i = 1; i <= n; i++) {
        std::cin >> vc[i - 1];

        response += vc[i - 1] * vc[i - 1] * (n - 1);
        partial_sum += vc[i - 1];
    }


    for (auto i = 0; i < n; i++) {
        response -= (partial_sum - vc[i]) * vc[i];
    }

    std::cout << response << std::endl;
}