#include <iostream>
#include <vector>

int main() {
    int t, n, k;


    std::cin >> t;
    std::vector response(t, 0);

    for (int i = 0; i < t; i++) {
        std::cin >> n >> k;

        int number;
        int number_even = 0;
        int distance_to_5 = 4;
        int distance_to_3 = 2;

        for (int j = 0; j < n; j++) {
            std::cin >> number;

            if (number % 2 == 0) {
                number_even++;
            }

            if (k == 5 and distance_to_5 > 0) {
                if (number % 5 == 0) {
                    distance_to_5 = 0;
                } else {
                    distance_to_5 = std::min(distance_to_5, 5 - number % 5);
                }
            }

            if (k == 3 and distance_to_3 > 0) {
                if (number % 3 == 0) {
                    distance_to_3 = 0;
                } else {
                    distance_to_3 = std::min(distance_to_3, 3 - number % 3);
                }
            }
        }

        if (k == 2) {
            if (number_even == 0) {
                response[i] = 1;
            }
        } else if (k == 5) {
            response[i] = distance_to_5;
        } else if (k == 3) {
            response[i] = distance_to_3;
        } else if (k == 4) {
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
