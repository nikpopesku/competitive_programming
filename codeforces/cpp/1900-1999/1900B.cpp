#include <iostream>
#include <vector>

int main() {
    int t;
    int a, b, c;


    std::cin >> t;
    std::vector response(t, std::vector(3, 0));

    for (int i = 0; i < t; i++) {
        std::cin >> a >> b >> c;

        if (std::abs(b - c) % 2 == 0) {
            response[i][0] = 1;
        }

        if (std::abs(a - c) % 2 == 0) {
            response[i][1] = 1;
        }

        if (std::abs(a - b) % 2 == 0) {
            response[i][2] = 1;
        }
    }

    for (auto &row: response) {
        for (int i = 0; i < row.size(); i++) {
            std::cout << row[i];

            if (i < row.size() - 1) {
                std::cout << ' ';
            }
        }

        std::cout << std::endl;
    }


    return 0;
}
