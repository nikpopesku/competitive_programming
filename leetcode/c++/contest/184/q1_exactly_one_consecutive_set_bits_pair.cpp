#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    bool consecutiveSetBits(const int n) {
        int pair_count = 0;

        for (int i = 0; i < 32 - 1; ++i) {
            int current_bit = (n >> i) & 1;
            int next_bit = (n >> (i + 1)) & 1;

            if (current_bit && next_bit) {
                ++pair_count;
            }
        }

        return pair_count == 1;
    }
};

int main() {
    auto s = Solution();

    cout << boolalpha << s.consecutiveSetBits(6) << endl; //true
    cout << boolalpha << s.consecutiveSetBits(5) << endl; //false
    cout << boolalpha << s.consecutiveSetBits(30) << endl; //false
}
