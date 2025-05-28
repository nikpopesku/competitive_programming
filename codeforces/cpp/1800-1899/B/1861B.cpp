#include <iostream>
#include <vector>

using namespace std::string_literals;

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::string a, b;
        std::cin >> a >> b;
        bool ok = false;

        for (int j = 0; j < a.size() - 1; j++) {
            if (a[j] == '0' and a[j] == b[j] and a[j + 1] == '1' and a[j + 1] == b[j + 1]) {
                ok = true;
                break;
            }
        }

        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
