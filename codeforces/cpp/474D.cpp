#include <iostream>
#include <vector>

using std::vector;

int main()
{
    int t;
    int k;
    int min_flower;
    int max_flower;
    vector dp (10001, 0);

    std::cin >> t >> k;

    vector<int> response (t);

    for (int i = 0; i < t; i++) {
        std::cin >> min_flower >> max_flower;
        response.push_back(6);
    }

    for (const auto i: response) {
        std::cout << i << ' ';
    }


    return 0;
}