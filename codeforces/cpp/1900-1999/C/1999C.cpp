#include <iostream>

int main() {
    int t;
    std::cin >> t;
    int n, s, m;
    int l, r;
    int start;
    std::string response;


    for (auto i = 0; i < t; i++) {
        start = 0;
        response = "NO";

        std::cin >> n >> s >> m;

        for (auto j = 0; j < n; j++) {
            std::cin >> l >> r;

            if (response == "NO") {
                if (l - start >= s) {
                    response = "YES";
                } else {
                    start = r;
                }
            }
        }

        if (response == "NO" and m - start >= s) response = "YES";

        std::cout << response << std::endl;
    }
}
