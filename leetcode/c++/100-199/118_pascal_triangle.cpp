#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle(numRows);
        for (int i = 0; i < numRows; ++i) {
            vector<int> current_row(i + 1, 0);
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i) {
                    current_row[j] = 1;
                } else {
                    current_row[j] = triangle.back()[j - 1] + triangle.back()[j];
                }
            }

            triangle.push_back(current_row);
        }

        return triangle;
    }
};


int main() {
    auto s = Solution();
    auto triangle = s.generate(5);
    for (int i = 0; i < triangle.size(); ++i) {
        for (int j = 0; j < static_cast<int>(triangle.size()); ++j) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}
