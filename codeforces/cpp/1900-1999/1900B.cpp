#include <iostream>
#include <vector>

using std::vector;

int main() {
    int t;
    int a, b, c;


    std::cin >> t;
    vector response(t, vector(3, 0));

    for (int i = 0; i < t; i++) {
        std::cin >> a >> b >> c;

        if (std::abs(b - c) % 2 == 0 and std::abs(b - c) / 2 < a) {
            response[i][0] = 1;
        }

        if (std::abs(a - c) % 2 == 0 and std::abs(a - c) / 2 < b) {
            response[i][1] = 1;
        }

        if (std::abs(a - b) % 2 == 0 and std::abs(a - b) / 2 < c) {
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
