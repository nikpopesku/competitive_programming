#include <iostream>
#include <numeric>
#include <queue>
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

        int root = -1;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] > 1) {
                return false;
            }

            if (indegree[i] == 0) {
                if (root != -1) {
                    return false;
                }

                root = i;
            }
        }

        if (root == -1) {
            return false;
        }

        queue<int> q;
        q.push(root);
        int visited = 1;


        while (!q.empty()) {
            auto elem = q.front();
            q.pop();
            if (leftChild[elem] != -1) {
                q.push(leftChild[elem]);
                ++visited;
            }

            if (rightChild[elem] != -1) {
                q.push(rightChild[elem]);
                ++visited;
            }
        }

        return visited == n;
    }
};

int main() {
    Solution s;

    vector<int> a = {1,0,3,-1};
    vector<int> b = {-1,-1,-1,-1};
    cout << boolalpha << s.validateBinaryTreeNodes(4, a, b);

    return 0;
}
