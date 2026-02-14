#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, m, u, v;
    cin >> n >> m;

    vector adj(n + 1, vector<int>());
    vector color(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    color[1] = 0;
    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        const auto elem = st.top();
        const int nei_color = color[elem] == 1 ? 0 : 1;
        st.pop();

        for (auto nei: adj[elem]) {
            if (color[nei] != -1 && color[nei] != nei_color) {
                cout << "NO\n";
                return 0;
            }

            if (color[nei] != -1 && color[nei] == nei_color) {
                continue;
            }

            st.push(nei);
            color[nei] = nei_color;
        }
    }


    return 0;
}
