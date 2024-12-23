#include <iostream>
#include <unordered_map>

int main() {
    int t;
    int n, m;
    int a, b, d;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> n >> m;

        std::string response = "YES";
        std::unordered_map<int, long long> places;

        for (auto k = 0; k < m; k++) {
            std::cin >> a >> b >> d;

            auto it_a = places.find(a);
            auto it_b = places.find(b);
            if (it_a == places.end() and it_b == places.end()) {
                places[a] = 1;
                places[b] = 1 + d;
            } else if (it_a != places.end() and it_b == places.end()) {
                places[b] = 1 + d;
            } else if (it_a->second + d != it_b->second) {
                response = "NO";

                break;
            }
        }

        std::cout << response << std::endl;
    }

    return 0;
}