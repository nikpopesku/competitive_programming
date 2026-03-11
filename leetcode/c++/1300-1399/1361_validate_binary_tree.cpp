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

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                visited[i] = true;
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

        for (const bool i: visited)
            if (!i) {
                return false;
            }

        return true;
    }
};

int main() {
    Solution s;

    vector<int> a = {1, -1, 3, -1};
    vector<int> b = {2, -1, -1, -1};
    cout << boolalpha << s.validateBinaryTreeNodes(4, a, b) << '\n'; //true

    vector<int> a1 = {1, -1, 3, -1};
    vector<int> b1 = {2, 3, -1, -1};
    cout << boolalpha << s.validateBinaryTreeNodes(4, a1, b1) << '\n'; //false

    vector<int> a2 = {1, 0};
    vector<int> b2 = {-1, -1};
    cout << boolalpha << s.validateBinaryTreeNodes(2, a2, b2) << '\n'; //false

    vector<int> a3 = {3, -1, 1, -1};
    vector<int> b3 = {-1, -1, 0, -1};
    cout << boolalpha << s.validateBinaryTreeNodes(4, a3, b3) << '\n'; //false

    return 0;
}
