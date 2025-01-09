#include <iostream>
#include <vector>
#include <map>

int main() {
    unsigned int t, k, n, value;
    std::cin >> t;
    unsigned int N = 1e3;
    unsigned int factor = 1;
    unsigned int counter = 0;

    std::map<unsigned int, unsigned int> number;

    for (auto i = 1; i <= N; i++) {
        number[i] = i;
    }

    std::vector<unsigned int> data(N);


    while (!number.empty() and factor <= N) {
        for (auto i = 1; i <= N; i += 2) {
            value = factor * i;
            if (value > N) break;

            auto it = number.find(value);
            if (it != number.end()) {
                data[counter] = value;
                number.erase(it);
                counter++;
            }
        }

        factor++;
    }


    for (auto i = 0; i < t; i++) {
        std::cin >> n >> k;

        counter = 0;

        for (auto j : data) {
            if (j <= n) counter++;

            if (counter == k) {
                std::cout << j << std::endl;

                break;
            }
        }
    }
}
