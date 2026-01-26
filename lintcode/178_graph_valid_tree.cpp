#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(const int n, const vector<vector<int> > &edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        unordered_map<int, vector<int> > adj;

        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int current = 0;
        stack<int> st;

        for (auto e: adj[current]) {
            st.push(e);
        }

        set visited = {0};

        while (!st.empty()) {
            auto elem = st.top();

            if (!visited.contains(elem)) {
                visited.insert(elem);

                for (auto neighbour: adj[elem]) {
                    st.push(neighbour);
                }
            }
        }

        return visited.size() == n - 1;
    }
};

int main() {
    Solution s;

    vector<vector<int> > a = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << s.validTree(5, a) << endl; //1

    vector<vector<int> > b = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << s.validTree(b, 5) << endl; //0

    return 0;
}
