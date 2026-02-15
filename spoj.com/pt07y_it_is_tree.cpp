#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N, M, u, v;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1, vector<int>());

    for (int i = 0; i < M; ++i) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (M != N - 1) {
        cout << "NO\n";

        return 0;
    }

    stack<int> st;
    st.push(1);
    vector<bool> visited(N + 1, false);
    visited[1] = true;

    while (!st.empty()) {
        const int elem = st.top();
        st.pop();

        for (auto nei: adj[elem]) {
            if (!visited[nei]) {
                st.push(nei);
                visited[nei] = true;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            cout << "NO\n";

            return 0;
        }
    }

    cout << "YES\n";
}
