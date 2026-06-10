#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> closestPrimes(const int left, const int right) {
        vector v(right + 1, true);

        for (int i = 2; i <= right; ++i) {
            if (v[i] == false) continue;
            int j = i + i;

            while (j <= right) {
                v[j] = false;
                j += i;
            }
        }

        int first = 0, second = 0, third = 0;
        int min_value = right;
        vector<int> numbers(2, -1);

        for (int i = left; i <= right; ++i) {
            if (v[i] == true) {
                first = second;
                second = third;
                third = i;

                if (second != 0) {
                    if (third - second < min_value) {
                        min_value = third - second;
                        numbers[0] = second;
                        numbers[1] = third;
                    }
                }
                if (first != 0) {
                    if (second - first < min_value) {
                        min_value = second - first;
                        numbers[0] = first;
                        numbers[1] = second;
                    }
                }
            }
        }

        return numbers;
    }
};

int main() {
    auto s = Solution();

    for (const auto &x: s.closestPrimes(10, 19)) {
        cout << x << ' '; //[11,13]
    }
    cout << '\n';

    for (const auto &x: s.closestPrimes(4, 6)) {
        cout << x << ' '; //[-1,-1]
    }
    cout << '\n';
}
