#include <iostream>
#include <vector>

int main() {
    int t;
    int n;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;

        std::vector points_x(n, 0);
        std::vector points_y(n, 0);

        int response = 0;

        for (int j = 0; j < n; j++) {
            std::cin >> points_x[j] >> points_y[j];
        }

        for (int j = 0; j < points_x.size() - 1; j++) {
            for (int k = j + 1; k < points_x.size(); k++) {
                if (std::abs(points_x[j] - points_x[k]) == std::abs(points_y[j] - points_y[k]) or points_x[j] == points_x[k] or points_y[j] == points_y[k]) {
                    response += 2;
                }
            }
        }

        std::cout << response << std::endl;
    }

    return 0;
}