#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        digits.resize(n);
        string response;
        int block_size = 1;
        for (int i = 1; i < n; ++i) block_size *= i;
        int m = n;

        while (k) {
            int index = k / block_size;
            if (k % block_size > 0) ++index;
            response += to_string(digits[index - 1]);
            digits.erase(digits.begin() + index - 1);
            --m;
            k -= block_size;
            block_size /= m;
        }

        response += to_string(digits[0]);


        return response;
    }
};

int main() {
    auto s = Solution();

    cout << s.getPermutation(3, 3) << '\n'; //213
    cout << s.getPermutation(4, 9) << '\n'; //2314
    cout << s.getPermutation(3, 1) << '\n'; //123
}
