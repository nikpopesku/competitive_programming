#include <iostream>
#include <vector>

using namespace std::string_literals;

int main() {
    int t;
    std::string a, b;

    std::cin >> t;

    std::vector response(t, "NO"s);

    for (int i = 0; i < t; i++) {
        std::cin>>a>>b;
        size_t most_right_zero_a = 0, most_right_zero_b = 0, most_left_one_a = a.size() - 1, most_left_one_b = b.size() - 1;

        for (int j=1; j < a.size() - 1; j++) {
            if (a[j] == '0' and j > most_right_zero_a) most_right_zero_a = j;
            if (a[j] == '1' and j < most_left_one_a) most_left_one_a = j;
            if (b[j] == '0' and j > most_right_zero_b) most_right_zero_b = j;
            if (b[j] == '1' and j < most_left_one_b) most_left_one_b = j;
        }

        if (most_right_zero_a == most_right_zero_b or most_left_one_a == most_left_one_b) {
            response[i] = "YES"s;
        }
    }


    for (int j = 0; j < response.size(); j++) {
        std::cout << response[j] << std::endl;
    }

    return 0;
}
