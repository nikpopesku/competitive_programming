#include <iostream>
#include <vector>

int main() {
    int n;
    int abs_max = 0;
    int last_elem = 0;
    int current_seq = 0;
    int last_seq = 0;
    std::cin >> n;

    for (auto i = 0; i < n; i++) {
        int number;
        std::cin >> number;

        if (number != last_elem) {
            int local_max = std::min(last_seq, current_seq);
            abs_max = std::max(abs_max, local_max);
            last_elem = number;
            last_seq = current_seq;
            current_seq = 1;
        } else {
            current_seq++;
        }
    }
    const int local_max = std::min(last_seq, current_seq);
    abs_max = std::max(abs_max, local_max);

    std::cout << abs_max * 2 << std::endl;

    return 0;
}
