#include <iostream>
#include <vector>

int main() {
    int n;

    std::cin >> n;
    std::vector<int> v(n);
    long long sum = 0;
    long long response = 0;
    long long x;

    for (auto i = 0; i < n; i++) {
        std::cin >> v[i];
        sum += v[i];
    }

    std::cin >> x;

    if (sum > x) {
        sum = 0;
        for (auto i = 0; i < n; i++) {
            sum += v[i];

            if (sum > x) {
                std::cout << i + 1 << std::endl;

                break;
            }
        }
    } else {
        response = n * (x / sum);
        x -= sum * (x / sum);
        sum = 0;

        for (auto i = 0; i < n; i++) {
            sum += v[i];

            if (sum > x) {
                std::cout << response + i + 1 << std::endl;

                break;
            }
        }
    }
}