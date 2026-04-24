#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(const int numRows) {
        vector<vector<int> > response;

        for (int row = 0; row < numRows; ++row) {
            vector<int> row_vec(row + 1, 1);
            for (int col = 0; col <= row; ++col) {
                if (col != 0 && col != row) {
                    row_vec[col] = response.back()[col - 1] + response.back()[col];
                }
            }
            response.push_back(std::move(row_vec));
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    for (auto e: s.generate(5)) {
        for (auto x: e) cout << x << ' ';
        cout << '\n';
    }
}
