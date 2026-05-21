#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
    }
};

int main() {
    auto s = Solution();

    vector<vector<char> > matrix = {
        {"1", "0", "1", "0", "0"}, {"1", "0", "1", "1", "1"}, {"1", "1", "1", "1", "1"}, {"1", "0", "0", "1", "0"}
    };

    for (auto row: s.maximalRectangle(matrix)) {
        for (auto cell: row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}
