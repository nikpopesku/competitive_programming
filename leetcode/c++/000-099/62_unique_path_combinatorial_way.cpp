#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int LIMIT = 100;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> factorial(LIMIT, 1);
        for (int i = 2; i < LIMIT; ++i) {
            factorial[i] = factorial[i] * i;
            if (factorial[i] >= 2e9) break;
        }
    }
};

int main() {
    auto s = Solution();

    cout << s.uniquePaths(3, 7) << '\n';
}
