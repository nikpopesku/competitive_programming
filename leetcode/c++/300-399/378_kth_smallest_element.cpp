#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(n + 1, 0) {
    }

    void update(int index) {
        for (++index; index <= n; index += index & -index) {
            ++tree[index];
        }
    }

    int find_kth(int k) {
        int pos = 0;

        return pos;
    }

private:
    int n;
    vector<int> tree;
};

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
        Bit bt(static_cast<int>(v.size()));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                const int idx = lower_bound(v.begin(), v.end(), matrix[i][j]) - v.begin();
                bt.update(idx);
            }
        }

        return v[bt.find_kth];
    }
};

int main() {
    auto s = Solution();
    vector<vector<int> > matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << s.kthSmallest(matrix, 8) << endl; //13

    vector<vector<int> > matrix2 = {{-5}};
    cout << s.kthSmallest(matrix2, 1) << endl; //-5
}
