#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, const vector<vector<int> > &edges, const int source, const int destination) {
        unordered_map<int, vector<int> > adj;

        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        stack<int> st;
        vector visited(n, false);
        st.push(source);

        while (!st.empty()) {
            const auto elem = st.top();
            st.pop();

            if (visited[elem]) {
                continue;
            }

            visited[elem] = true;

            if (elem == destination) {
                return true;
            }

            for (auto neighbour: adj[elem]) {
                if (!visited[neighbour]) {
                    st.push(neighbour);
                }
            }
        }

        return false;
    }
};


int main() {
    auto s = Solution();

    const vector<vector<int> > edges = {{0, 1}, {1, 2}, {2, 0}};
    cout << s.validPath(3, edges, 0, 2) << endl; //1

    const vector<vector<int> > edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    cout << s.validPath(6, edges2, 0, 5) << endl; //0
}
