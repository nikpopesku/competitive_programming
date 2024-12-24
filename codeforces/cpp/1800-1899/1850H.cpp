#include <iostream>
#include <vector>
#include <map>

const int N = 2e5+5;

std::vector<bool> visited (N, false);
std::vector c(N, std::vector<int> (3, 0));
std::vector<int> val(N);
std::vector<std::pair<int, int>> adj[N];

void dfs(int u) {
    visited[u] = true;

    for (auto &p: adj[u]) {
        int b = p.first;
        int d = p.second;
        val[b] = val[u] + d;

        if (!visited[b]) {
            dfs(b);
        }
    }
}


int main() {
    int t;
    int n, m;
    int a, b, d;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> n >> m;

        std::string response = "YES";

        for (auto k = 0; k < m; k++) {
            std::cin >> a >> b >> d;
            adj[a].emplace_back(b, d);
            adj[b].emplace_back(a, -d);
            c.push_back({a, b, d});
        }

        for (int j = 1; j <= n; j++) {
            if (!visited[j]) dfs(j);
        }

        for (auto & j : c) {
            a = val[j[0]]; b = val[j[1]]; d = j[2];

            if (a + d != b) {
                response = "NO";

                break;
            }
        }

        std::cout << response << std::endl;
    }

    return 0;
}