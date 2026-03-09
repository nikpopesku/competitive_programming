#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool validTree(int n, const vector<vector<int> > &edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector adj(n, vector<int>());

        for (auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector visited(n, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;

        while (!st.empty()) {
            const auto e = st.top();
            st.pop();

            for (auto nei: adj[e]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    st.push(nei);
                }
            }
        }

        for (auto e: visited) {
            if (e == false) return false;
        }

        return true;
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << boolalpha << s.validTree(5, edges) << '\n'; //true

    vector<vector<int> > edges2 = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    cout << boolalpha << s.validTree(5, edges2) << '\n'; //false
}
