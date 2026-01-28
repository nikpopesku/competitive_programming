#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, const vector<vector<int> > &edges, const int source, const int destination) {
        map<int, vector<int> > adj;

        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        stack<int> st;
        set<int> visited;
        st.push(source);
        visited.insert(source);

        while (!st.empty()) {
            const auto elem = st.top();
            st.pop();

            if (visited.contains(elem)) {
                continue;
            }


            if (elem == destination) {
                return true;
            }

            for (auto neighbour: adj[elem]) {
                if (!visited.contains(neighbour)) {
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
