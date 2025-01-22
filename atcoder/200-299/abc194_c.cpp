#include <iostream>
#include <vector>


int main() {
    int n;
    std::cin >> n;
    std::vector<int> vc(n);
    long long response = 0;
    long long partial_sum = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> vc[i - 1];

        response += vc[i - 1] * vc[i - 1] * n;
        partial_sum += vc[i - 1];
    }


    response -= partial_sum * partial_sum;

    std::cout << response << std::endl;
}