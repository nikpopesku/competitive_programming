#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

template<typename T>
typename std::vector<T>::iterator
insert_sorted(std::vector<T> &vec, T const &item) {
    return vec.insert
            (
                    std::upper_bound(vec.begin(), vec.end(), item),
                    item
            );
}


int main() {
    int t, n, k;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n >> k;

        int problem;
        std::vector<int> numbers;

        for (int j = 0; j < n; j++) {
            std::cin >> problem;
            insert_sorted(numbers, problem);
        }

        int largest_group = 1;
        int current_group = 1;
        for (int j = 1; j < numbers.size(); j++) {
            if (numbers[j] - numbers[j - 1] <= k) {
                current_group += 1;
            } else {
                largest_group = std::max(largest_group, current_group);
                current_group = 1;
            }
        }

        largest_group = std::max(largest_group, current_group);

        std::cout << numbers.size() - largest_group << std::endl;
    }

    return 0;
}