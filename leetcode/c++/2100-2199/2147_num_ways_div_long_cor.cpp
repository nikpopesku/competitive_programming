#include <iostream>

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

        return cur_seats < 2 ? 0 : static_cast<int>(num_ways);
    }
};

int main() {
    Solution s;

    cout << s.numberOfWays("SSPPSPS") << '\n'; //3
    cout << s.numberOfWays("PPSPSP") << '\n'; //1
    cout << s.numberOfWays("S") << '\n'; //0

    return 0;
}
