#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <tuple> // For structured binding clarity (optional)
#include <limits> // For numeric_limits

using namespace std;

const int INF = numeric_limits<int>::max() / 2; // Use a large value for infinity, avoiding overflow on +1

int main() {
    ios_base::sync_with_stdio(false); // Faster I/O
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    vector<vector<int>> dist(H, vector<int>(W, INF));
    deque<pair<int, int>> dq; // Use pair for coordinates {row, col}

    // Check if starting cell is valid (although problem implies it is)
    if (H > 0 && W > 0) {
        dist[0][0] = 0;
        dq.emplace_front(0, 0);
    } else {
        cout << 0 << endl; // Or handle as appropriate if 0x0 grid is possible
        return 0;
    }


    auto is_valid = [&](int r, int c) {
        return r >= 0 && r < H && c >= 0 && c < W;
    };

    // Directions for cost 0 moves (orthogonal)
    int dr0[] = {0, 0, 1, -1};
    int dc0[] = {1, -1, 0, 0};

    while (!dq.empty()) {
        // Using structured binding (C++17 onwards)
        auto [r, c] = dq.front();
        dq.pop_front();

        int d = dist[r][c];

        // --- Cost 0 Moves (Walk) ---
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr0[i];
            int nc = c + dc0[i];

            if (is_valid(nr, nc) && S[nr][nc] == '.') {
                // If we find a path with the same cost (d), update and push to front
                if (d < dist[nr][nc]) {
                    dist[nr][nc] = d;
                    dq.emplace_front(nr, nc);
                }
            }
        }

        // --- Cost 1 Moves (Punch) ---
        // Check the 5x5 neighborhood around (r, c)
        // The cost to reach any cell in this area via one punch is d + 1
        for (int nr_offset = -2; nr_offset <= 2; ++nr_offset) {
            for (int nc_offset = -2; nc_offset <= 2; ++nc_offset) {
                // Skip the direct orthogonal neighbors if they are roads (handled above)
                // Also skip the cell itself
                // More accurately, just check if the potential move requires a punch
                if (abs(nr_offset) + abs(nc_offset) <= 1) { // Optimization: skip direct neighbors and self if cost 0 possible
                    continue; // Let cost 0 handle these if applicable. If wall, cost 1 needed anyway
                }


                int nr = r + nr_offset;
                int nc = c + nc_offset;

                if (is_valid(nr, nc)) {
                    // If we find a path with cost d + 1 that's better than the current dist[nr][nc]
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        dq.emplace_back(nr, nc); // Push to back for cost 1 moves
                    }
                }
            }
        }
        // Correction: The 5x5 logic needs refinement. The punch cost applies when moving TO an adjacent wall.
        // Let's reconsider the cost 1 move properly.
        // From (r,c) with cost d:
        // Consider all neighbors (nr, nc) in the 5x5 area.
        // The cost to reach (nr, nc) is potentially d+1.

        // Re-implementing cost 1 section based on the 5x5 reach idea:
        for (int nr = r - 2; nr <= r + 2; ++nr) {
            for (int nc = c - 2; nc <= c + 2; ++nc) {
                // We are considering reaching (nr, nc) from (r, c) using one punch action
                // The cost for this transition is 1.
                if (abs(r - nr) + abs(c - nc) <= 1) {
                    // This is an adjacent cell. If it's a road '.', it's handled by cost 0 move.
                    // If it's a wall '#', we might need to punch.
                    // The cost 0 loop handles adjacent road cells optimally.
                    // We only need to consider non-adjacent cells or adjacent wall cells here for cost 1.
                    // Let the 5x5 loop handle all potential destinations reachable by 1 punch.
                }

                if(is_valid(nr, nc)){
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        dq.emplace_back(nr, nc);
                    }
                }
            }
        }

    }

    // The final answer is the minimum cost to reach the bottom-right cell
    cout << dist[H - 1][W - 1] << endl;

    return 0;
}