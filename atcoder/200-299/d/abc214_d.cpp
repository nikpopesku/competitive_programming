#include <iostream>
#include <vector>
#include <numeric> // For std::iota
#include <algorithm> // For std::sort
#include <tuple> // Optional: for storing edges alternatively

// Disjoint Set Union (DSU) structure
struct DSU
{
    std::vector<int> parent;
    std::vector<long long> sz; // Store component sizes as long long

    // Constructor initializes each node as its own parent with size 1
    explicit DSU(const int n) : parent(n), sz(n, 1LL)
    {
        std::iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    // Find the representative (root) of the set containing i, with path compression
    int find(const int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        // Path compression: point directly to the root
        return parent[i] = find(parent[i]);
    }

    // Unite the sets containing i and j, using union by size
    // Returns true if a merge happened, false otherwise
    bool unite(const int i, const int j)
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            // Union by size: attach smaller tree to larger tree
            if (sz[root_i] < sz[root_j])
            {
                std::swap(root_i, root_j);
            }
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j]; // Update the size of the merged component
            return true;
        }
        return false; // Already in the same set
    }

    // Get the size of the component containing i
    long long size(const int i)
    {
        return sz[find(i)];
    }
};

// Structure to represent an edge
struct Edge
{
    int u, v;
    int w; // Weight

    // Comparison operator for sorting edges by weight
    bool operator<(const Edge& other) const
    {
        return w < other.w;
    }
};

int main()
{
    // Faster I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Edge> edges;
    edges.reserve(n - 1); // Reserve space for efficiency

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        // Adjust to 0-based indexing
        edges.push_back({u - 1, v - 1, w});
    }

    // Sort edges by weight in non-decreasing order
    std::sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long total_max_weight_sum = 0;

    // Process edges in sorted order
    for (const auto& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        long long w = edge.w; // Use long long for weight calculation

        // Get sizes of the components before merging
        long long size_u = dsu.size(u);
        long long size_v = dsu.size(v);

        // The edge (u, v, w) is the maximum weight edge for paths
        // between any node in u's component and any node in v's component.
        // The number of such pairs is size_u * size_v.
        // Add the contribution to the total sum.
        total_max_weight_sum += w * size_u * size_v;

        // Merge the two components
        dsu.unite(u, v);
    }

    std::cout << total_max_weight_sum << std::endl;
}
