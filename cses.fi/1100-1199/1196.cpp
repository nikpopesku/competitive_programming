#include <iostream>
#include <vector>
#include <queue>
#include <utility> // For std::pair
#include <ranges>  // For output convenience (optional)

// Use long long for path costs as they can exceed 32-bit int
using ll = long long;
// Define a type alias for the pair in the priority queue: {cost, node}
using P = std::pair<ll, int>;

constexpr int MAXN = 100005; // Maximum number of nodes + 1

// Adjacency list: adj[u] contains pairs {v, w} for edges u -> v with weight w
std::vector<std::pair<int, int>> adj[MAXN];

// dist[i] will store the costs of the k shortest paths found to node i
std::vector<ll> dist[MAXN];

int main()
{
    // Faster I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; // Number of cities (nodes)
    int m; // Number of flight routes (edges)
    int k; // Number of shortest routes to find
    std::cin >> n >> m >> k;

    // Read graph edges
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        // Add directed edge u -> v with weight w
        adj[u].emplace_back(v, w);
    }

    // Min-priority queue storing {cost, node}
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

    // Start Dijkstra from node 1 with initial cost 0
    pq.emplace(0, 1);

    while (!pq.empty())
    {
        // Get the state {current_cost, current_node} with the smallest cost
        auto [current_cost, u] = pq.top();
        pq.pop();

        // If we have already found k shortest paths to node u,
        // this path and any further paths derived from it via u
        // cannot be among the top k for u. Skip.
        if (dist[u].size() >= k)
        {
            continue;
        }

        // This is the dist[u].size() + 1 shortest path found to node u. Record it.
        dist[u].push_back(current_cost);

        // Optimization: If we just found the k-th path to the destination (node n),
        // we could potentially break early if we are certain no shorter path exists.
        // However, the loop condition handles correctness, so we keep it simple.
        // if (u == n && dist[n].size() == k) {
        //     break; // Found all required paths to destination
        // }

        // Explore neighbors (relax edges)
        for (const auto& [fst, snd] : adj[u])
        {
            int v = fst; // Neighbor node
            const int weight = snd; // Edge weight
            ll new_cost = current_cost + static_cast<ll>(weight);

            // Only proceed if neighbor v hasn't received k paths yet.
            // If dist[v].size() == k, pushing more paths for v is unnecessary
            // unless one of the existing k paths in the pq leading to v gets
            // popped later with a higher cost than new_cost. But the outer check
            // 'if (dist[u].size() >= k)' effectively manages this.
            // We always push the potential path to the queue.
            // The check at the start of the loop ensures we only process
            // the necessary number of paths arriving at each node.
            if (dist[v].size() < k)
            {
                pq.emplace(new_cost, v);
            }
            // Note: We don't compare new_cost with existing distances in dist[v] here.
            // We rely on the priority queue and the count check (dist[u].size() < k)
            // to manage finding the k shortest paths correctly.
        }
    }

    // Output the k shortest path costs to node n.
    // They will be in non-decreasing order in dist[n].
    bool first = true;
    for (const ll path_cost : dist[n])
    {
        // C++11 range-based for loop
        if (!first)
        {
            std::cout << " ";
        }
        std::cout << path_cost;
        first = false;
    }
    std::cout << "\n";

    // Alternative C++20 ranges output:
    // for (bool first = true; ll path_cost : std::views::take(dist[n], k)) {
    //     std::cout << (first ? "" : " ") << path_cost;
    //     first = false;
    // }
    // std::cout << "\n";
}
