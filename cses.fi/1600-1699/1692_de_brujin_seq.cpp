#include<bits/stdc++.h>
#include<cmath>

using namespace std;

void dfs(vector<int> &result, const int start, vector<vector<int> > &adj) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int node = st.top();
        if (!adj[node].empty()) {
            st.push(adj[node].back());
            adj[node].pop_back();
        } else {
            result.push_back(node);
            st.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    const int mx = static_cast<int>(pow(2, n - 1));
    vector adj(mx, vector<int>());

    for (int i = 0; i < mx; ++i) {
        adj[i].push_back((i * 2 + 0) % mx);
        adj[i].push_back((i * 2 + 1) % mx);
    }

    vector<int> result;
    dfs(result, 0, adj);

    for (int i = 1; i < n - 1; ++i) cout << '0';
    for (auto &e: result) {
        cout << (e & 1);
    }
}
