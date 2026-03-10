#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int> > &edges) {
        vector adj(n, vector<int>());

        for (auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector visited(n, false);
        stack<int> st;
        int counter = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                st.push(i);
                visited[i] = true;
                ++counter;

                while (!st.empty()) {
                    auto e = st.top();
                    st.pop();

                    for (auto &nei: adj[e]) {
                        if (!visited[nei]) {
                            st.push(nei);
                            visited[nei] = true;
                        }
                    }
                }
            }
        }
 return counter;
    }
};


int main() {
    auto s = Solution();

    vector<vector<int> > edges = {{0, 1}, {1, 2}, {3, 4}};
    cout << boolalpha << s.countComponents(5, edges) << '\n'; //2

    vector<vector<int> > edges2 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    cout << boolalpha << s.countComponents(5, edges2) << '\n'; //1
}
