#include <iostream>
#include <vector>
#include <map>

int main() {
    int t, k, n, value;
    std::cin >> t;
    int N = 1e9;
    int factor = 1;
    int counter = 0;

    std::map<int, int> number;

    for (auto i = 1; i <= N; i++) {
        number[i] = i;
    }

    std::vector<int> data(N);


    while (!number.empty() and factor <= N) {
        for (auto i = 1; i <= N; i += 2) {
            value = factor * i;
            if (value > N) break;

            auto it = number.find(value);
            if (it != number.end()) {
                data.push_back(value);
                number.erase(it);
            }
        }

        factor++;
    }


    for (auto i = 0; i < t; i++) {
        std::cin >> n >> k;

        counter = 0;

        for (int j : data) {
            if (j <= n) counter++;

            if (counter == k) {
                std::cout << j << std::endl;
            }
        }
    }
}
