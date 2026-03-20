#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        vector<int> v;
        const int n = static_cast<int>(matrix.size());
        v.reserve(n * n);

        for (int i = 0; i < n; ++i) {
            v.insert(v.end(), matrix[i].begin(), matrix[i].end());
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
};

int main() {
    auto s = Solution();
    vector<vector<int> > matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << s.kthSmallest(matrix, 8) << endl; //13

    vector<vector<int> > matrix2 = {{-5}};
    cout << s.kthSmallest(matrix, 1) << endl; //-5
}
