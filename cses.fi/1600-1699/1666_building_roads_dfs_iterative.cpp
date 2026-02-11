#include <iostream>
#include <stack>
#include <vector>


using namespace std;

int dfs_iterative(const int start, const vector<vector<int> > &adj, vector<bool> &visited) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        const auto elem = st.top();
        st.pop();

        for (auto nei: adj[elem]) {
            if (!visited[nei]) {
                st.push(nei);
                visited[nei] = true;
            }
        }
    }

    return start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b;

    cin >> n >> m;

    vector adj(n + 1, vector<int>());

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector visited(n+1, false);
    vector<pair<int, int> > response;
    int previous = 0;

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;

        if (previous) {
            response.emplace_back(i, previous);
        }

        previous = dfs_iterative(i, adj, visited);
    }

    cout << response.size() << '\n';

    for (auto elem: response) {
        cout << elem.first << ' ' << elem.second << '\n';
    }
}
