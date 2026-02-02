#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    explicit Node(const int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(const int _val, const vector<Node *> &_neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        Node *newNode(node->val);

        for (const auto nei: node->neighbors) {
            Node *newNeighbour = cloneGraph(nei);
            newNode->neighbors.push_back(newNeighbour);
        }


        return newNode;
    }
};

int main() {
    Solution s; //{1}
    vector<vector<int> > a = {{1, 0}, {1, 2}, {1, 3}};
    vector<vector<int> > c = {{0, 1}, {0, 2}, {0, 3}, {3, 4}, {4, 5}};
    for (const auto elem: s.findMinHeightTrees(6, c)) {
        cout << elem << ' ';
    }
}
