#include <iostream>
#include <vector>

int main() {
    int t, n, k;


    std::cin >> t;
    std::vector response(t, 0);

    for (int i = 0; i < t; i++) {
        std::cin >> n >> k;

        std::vector numbers(n, 0);
        int number_even = 0;
        int distance_to_5 = 4;

        for (int j = 0; j < n; j++) {
            std::cin >> numbers[j];

            if (numbers[j] % 2 == 0) {
                number_even++;
            }

            if (k == 5 and distance_to_5 > 0) {
                distance_to_5 = std::min(distance_to_5, numbers[j] % 5);
            }

        }

        if (k == 2 and number_even == 0) {
            response[i] = 1;
        }

        if (k == 5) {
            response[i] = distance_to_5;
        }

        if (k == 4) {
            if (number_even == 0) {
                response[i] = 2;
            } else if (number_even < 2) {
                response[i] = 1;
            }
        }
    }

    for (const auto &elem: response) {
        std::cout << elem << std::endl;
    }

    return 0;
}
