#include <iostream>
#include <vector>
#include <string>

using namespace std::string_literals;

int main() {
    int t;
    std::string a, b;

    std::cin >> t;

    std::vector response(t, "NO"s);

    for (int i = 0; i < t; i++) {
        std::cin>>a>>b;

        if (a == b) {
            response[i] = "YES"s;
        }
    }


    for (int j = 0; j < response.size(); j++) {
        std::cout << response[j];

        if (j < response.size() - 1) std::cout << ' ';
    }

    std::cout << std::endl;

    return 0;
}
