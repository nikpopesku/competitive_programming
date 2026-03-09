#include <vector>
#include <iostream>
#include <stack>

using namespace std;

dfs(int node) {

}

class Solution {
public:
    bool validTree(int n, vector<vector<int> > &edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        vector visited(n, false);
        stack<int> st;
        st.push(0);
        visited[0] = true;

        while (!st.empty()) {
            const auto e = st.top();
            st.pop();

            for (auto nei: edges[e]) {
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
    cout << s.validTree(1, 2) << '\n'; //10
}
