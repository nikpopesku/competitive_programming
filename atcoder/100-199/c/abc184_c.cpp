#include <iostream>
#include <cmath>   // For std::abs
#include <cstdlib> // Alternatively for std::abs

// Use long long for coordinates to prevent potential overflow
using ll = long long;

int main() {
    // Optimize C++ standard streams
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;

    // Calculate absolute differences and Manhattan distance
    ll dr = std::abs(r1 - r2);
    ll dc = std::abs(c1 - c2);
    ll manhattan_dist = dr + dc;

    // --- Case 0: 0 Moves ---
    if (dr == 0 && dc == 0) {
        std::cout << 0 << "\n";
        return 0;
    }

    // --- Case 1: 1 Move ---
    // Check the three conditions for a single move
    if (r1 + c1 == r2 + c2 ||      // Diagonal 1
        r1 - c1 == r2 - c2 ||      // Diagonal 2
        manhattan_dist <= 3)       // Manhattan distance <= 3
    {
        std::cout << 1 << "\n";
        return 0;
    }

    // --- Case 2: 2 Moves ---
    // Check the conditions for two moves
    bool same_parity = ((r1 + c1) % 2 == (r2 + c2) % 2); // Same color check

    if (same_parity ||                     // Two diagonal moves possible
        manhattan_dist <= 6 ||             // Two Manhattan <= 3 moves possible
        std::abs((r1 + c1) - (r2 + c2)) <= 3 || // Close to diagonal 1
        std::abs((r1 - c1) - (r2 - c2)) <= 3    // Close to diagonal 2
       )
    {
        std::cout << 2 << "\n";
        return 0;
    }

    // --- Case 3: 3 Moves ---
    // If none of the above conditions are met, 3 moves are always sufficient
    std::cout << 3 << "\n";

    return 0;
}