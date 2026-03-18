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

        int answer = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int min_value = h[i][j];
                for (int k = 0; k <= j; ++k) {
                    min_value = min(min_value, h[i][k]);
                }
                answer += min_value;
            }
        }

        return answer;
    }
};

int main() {
    Solution s;

    const vector<vector<int> > mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << s.numSubmat(mat) << endl; //13

    const vector<vector<int> > mat2 = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
    cout << s.numSubmat(mat2) << endl; //24

    return 0;
}
