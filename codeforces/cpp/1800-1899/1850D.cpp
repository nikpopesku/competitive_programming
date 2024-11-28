#include <iostream>
#include <vector>
#include <map>

int main()
{
    int t;
    int n;
    int k;
    int a;
    bool found;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n >> k;

        std::map<std::vector<int>, int> problems;

        for (int j = 0; j < n; j++) {
            std::cin >> a;
            found = false;
            for (const auto &problem : problems)
            {

                if (problem.first[0] >= a and problem.first[1] <= a) {
                    found = true;
                    std::vector<int> tempV = {std::min(a-k, problem.first[0]), std::max(a+k, problem.first[1])};
                    problems[tempV] = problem.second + 1;
                    break;
                }
            }
            if (!found) {
                std::vector<int> tempV = {a-k, a+k};
                problems[tempV] = 1;
            }
        }

        int max_element = 0;
        for (const auto &problem : problems)
        {
            max_element = std::max(max_element, problem.second);
        }

        std::cout << n - max_element << std::endl;
    }

    return 0;
}