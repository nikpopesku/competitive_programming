#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    int countComponents(const int n, const vector<vector<int> > &edges) {
        vector visited(n, false);
        stack<int> st;
        int counter = 0;

        map<int, vector<int> > adj;

        for (auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++counter;
                st.push(i);

                while (!st.empty()) {
                    const auto elem = st.top();
                    st.pop();

                    if (visited[elem]) {
                        continue;
                    }

                    visited[elem] = true;

                    for (auto neighbour: adj[elem]) {
                        if (!visited[neighbour]) {
                            st.push(neighbour);
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

    const vector<vector<int> > edges = {{0, 1}, {0, 2}};
    cout << s.countComponents(3, edges) << endl; //1

    const vector<vector<int> > edges2 = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
    cout << s.countComponents(6, edges2) << endl; //2
}
