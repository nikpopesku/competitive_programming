#include <print>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> current_row, previous_row;

        for (int i = 0; i <= rowIndex; ++i) {
            current_row.resize(i + 1);
            for (int j = 0; j < i + 1; ++j) {
                current_row[j] = j == 0 || j == i ? 1 : previous_row[j] + previous_row[j - 1];
            }

            previous_row = std::move(current_row);
        }

        return current_row;
    }
};

int main() {
    auto s = Solution();
    auto triangle = s.getRow(3);
    println("{}", triangle);
}
