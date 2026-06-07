#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    bool consecutiveSetBits(const int n) {
        const unsigned int n1 = static_cast<unsigned int>(n);
        unsigned int m = ~n1;
        const int bit_length = bit_width(n1);
        int counter = -1;

        while (m > 0) {
            ++counter;
            if (m & 1) {
                break;
            }
            m = m >> 1;
        }

        return counter == 0 || counter == bit_length - 1;
    }
};

int main() {
    auto s = Solution();

    cout << boolalpha << s.consecutiveSetBits(6) << endl; //true
    cout << boolalpha << s.consecutiveSetBits(5) << endl; //false
}
