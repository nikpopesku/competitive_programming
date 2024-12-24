#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

void dfs(int u) {

}


int main() {
    int t;
    int n, m;
    int a, b, d;
    const int N = 2e5+5;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> n >> m;

        std::vector<bool> visited (n, false);
        std::vector c(m, std::vector<int> (3, 0));
        std::vector<std::pair<int, int>> adj[N];

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
            a = j[0]; b = j[1]; d = j[2];

            if (a + d != b) {
                response = "NO";

                break;
            }
        }

        std::cout << response << std::endl;
    }

    return 0;
}