#include <iostream>
#include <vector>

int main() {
    int t;
    int l, r;
    std::cin >> t;

    std::vector<int> steps;
    int step = 1;

    while (step <= 200000) {
        step *= 3;
        steps.push_back(step);
    }

    for (int i = 0; i < t; i++) {
        int response = 0;
        int index = 0;
        std::cin >> l >> r;

        while (l >= steps[index]) index++;
        response = index + 1;

        int current = l;
        while (r >= steps[index]) {
            response += (steps[index] - current) * (index + 1);
            current = steps[index];
            index++;
        }

        response += (std::min(steps[index], r + 1) - current) * (index + 1);


        std::cout << response << std::endl;
    }
}
