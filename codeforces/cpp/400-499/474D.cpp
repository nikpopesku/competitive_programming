#include <algorithm>
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
    vector<int> min_value (t);
    vector<int> max_value (t);

    for (int i = 0; i < t; i++) {
        std::cin >> min_flower >> max_flower;
        min_value.push_back(min_flower);
        max_value.push_back(max_flower);
    }

    for (int i = 1; i < k; i++) {
        dp[i] = 1;
    }

    auto absolute_max = std::max_element(max_value.begin(), max_value.end());

    for (auto i = k; i <= *absolute_max; i++) {
        dp[i] = 1;
    }

    for (const auto i: response) {
        std::cout << i << ' ';
    }


    return 0;
}