#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node *, Node *> cloned;

        return cloneDfs(node, cloned);
    }

private:
    Node *cloneDfs(Node *node, unordered_map<Node *, Node *> &cloned) {
        if (auto it = cloned.find(node); it != cloned.end()) {
            return it->second;
        }

        auto newNode = new Node(node->val);
        newNode->neighbors.reserve(node->neighbors.size());
        cloned[node] = newNode;

        for (auto *nei: node->neighbors) {
            newNode->neighbors.push_back(cloneDfs(nei, cloned));
        }

        return newNode;
    }
};

int main() {
}
