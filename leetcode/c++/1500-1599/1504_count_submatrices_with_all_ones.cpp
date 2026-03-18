#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int numSubmat(const vector<vector<int> > &mat) {
        vector<vector<int>> h = mat;
        const int n = static_cast<int>(h.size());
        const int m = static_cast<int>(h[0].size());

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (h[i][j] == 1) {
                    h[i][j] += h[i-1][j];
                }
            }
        }

        int xxxx = 5;
    }
};

int main() {
    Solution s;

    vector<vector<int> > mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << s.numSubmat(mat) << endl; //13

    vector<vector<int> > mat2 = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
    cout << s.numSubmat(mat2) << endl; //24

    return 0;
}
