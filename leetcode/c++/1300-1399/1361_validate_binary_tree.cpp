#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                ++indegree[leftChild[i]];
            }

            if (rightChild[i] != -1) {
                ++indegree[rightChild[i]];
            }
        }

        int count_zero = 0;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] > 1) {
                return false;
            }

            if (indegree[i] == 0) {
                ++count_zero;
            }
        }

        return count_zero == 1;
    }
};

int main() {
    Solution s;

    vector<int> a = {1,0,3,-1};
    vector<int> b = {-1,-1,-1,-1};
    s.validateBinaryTreeNodes(4, a, b);

    return 0;
}
