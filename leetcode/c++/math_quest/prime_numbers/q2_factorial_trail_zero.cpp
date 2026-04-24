#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int value = 5;
        int response = 0;

        while (value <= n) {
            response += n / value;
            value *= 5;
        }


        return response;
    }
};

int main() {
    auto s = Solution();

    cout << s.trailingZeroes(3) << '\n'; //0
    cout << s.trailingZeroes(5) << '\n'; //1
    cout << s.trailingZeroes(0) << '\n'; //0
    cout << s.trailingZeroes(10) << '\n'; //2
    cout << s.trailingZeroes(15) << '\n'; //2
}
