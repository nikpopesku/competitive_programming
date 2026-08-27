#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;

class Solution {
public:
    int numberOfWays(string corridor) {
        ll cur_seats = 0;
        ll cur_space = 0;
        ll num_ways = 1;

        for (const auto i: corridor) {
            if (cur_seats == 2) {
                if (i == 'P') {
                    ++cur_space;
                } else {
                    num_ways = num_ways * (cur_space + 1) % MD;
                    cur_space = 0;
                    cur_seats = 0;
                }
            }
            if (i == 'S' && cur_seats != 2) {
                ++cur_seats;
            }
        }

        cout << num_ways << '\n';
    }
};

int main() {
    Solution s;

    s.numberOfWays("SSPPSPS"); //3
    s.numberOfWays("PPSPSP"); //1
    s.numberOfWays("S"); //0

    return 0;
}
