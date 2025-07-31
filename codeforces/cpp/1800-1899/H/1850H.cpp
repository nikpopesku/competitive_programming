#include "bits/stdc++.h"
using namespace std;

#define ll long long

#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()

#define            pb                push_back
#define          sz(a)               (int)a.size()

#define int long long
const int N = 2e5 + 5;
vector<pair<int, int>> adj[N];
int val[N], vis[N];
void dfs(int u) {
    vis[u] = 1;
    for(auto x: adj[u]) {
        int v = x.first, w = x.second;
        if(!vis[v]) {
            val[v] = val[u] + w;
            dfs(v);
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        adj[i].clear();
        vis[i] = 0, val[i] = 0;
    }
    vector<array<int, 3>> c;
    for(int i = 1; i <= m; ++i) {
        int a, b, d; cin >> a >> b >> d;
        adj[a].pb({b, d});
        adj[b].pb({a, -d});
        c.pb({a, b, d});
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= m; ++i) {
        int a = c[i - 1][0], b = c[i - 1][1], d = c[i - 1][2];
        if(val[a] + d != val[b]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
