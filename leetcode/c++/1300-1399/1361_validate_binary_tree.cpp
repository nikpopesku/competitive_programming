#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(const int n, vector<int> &leftChild, vector<int> &rightChild) {
        int counter = 0;
        vector indegree(n, 0);

        for (auto &i: leftChild) {
            if (i != -1) {
                ++counter;
                ++indegree[i];
            }
        }
        for (auto &i: rightChild) {
            if (i != -1) {
                ++counter;
                ++indegree[i];
            }
        }

        if (counter != n - 1) return false;

        vector visited(n, false);

        queue<int> q;

        for (const auto &i: indegree) {
            if (i == 0) {
                q.push(i);
                break;
            }
        }

        while (!q.empty()) {
            const auto e = q.front();
            q.pop();

            for (auto &nei: {leftChild[e], rightChild[e]}) {
                if (nei != -1 && !visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }

        for (const bool i: visited) if (!i) return false;

        return true;
    }
};

int main() {
    Solution s;

    vector<int> a = {1, 0, 3, -1};
    vector<int> b = {-1, -1, -1, -1};
    cout << boolalpha << s.validateBinaryTreeNodes(4, a, b);

    return 0;
}
