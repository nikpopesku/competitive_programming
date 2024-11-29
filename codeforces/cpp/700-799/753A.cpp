#include <iostream>
#include <vector>

int main() {
    int n;
    int i = 1;
    int counter = 0;
    std::vector<int> candies{};

    std::cin >> n;


    while (n > 0) {
        if (n - i >= 0) {
            counter++;
            candies.push_back(i);
            n -= i;
            i++;
        } else {
            candies[candies.size() - 1] += n;
            n = 0;
        }
    }

    std::cout << counter << std::endl;

    for (int j = 0; j < candies.size(); j++) {
        std::cout << candies[j];

        if (j < candies.size() - 1) std::cout << ' ';
    }

    std::cout << std::endl;

    return 0;
}
