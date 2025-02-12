#include <iostream>
#include <set>

using namespace std;

int main() {
    unsigned int n, k, tasteness, max_tasteness = 0, dislike;
    set<unsigned int> max_tasteness_pool{};
    std::cin >> n >> k;

    for (auto i = 1; i <= n; i++) {
        std::cin >> tasteness;

        if (tasteness > max_tasteness) {
            max_tasteness = tasteness;
            max_tasteness_pool = {};
            max_tasteness_pool.insert(i);
        } else if (tasteness == max_tasteness) {
            max_tasteness_pool.insert(i);
        }
    }

    string response = "No";

    for (auto i = 1; i <= k; i++) {
        std::cin >> dislike;

        if (response == "No" and max_tasteness_pool.count(dislike) > 0) {
            response = "Yes";
        }
    }

    std::cout << response << std::endl;
}