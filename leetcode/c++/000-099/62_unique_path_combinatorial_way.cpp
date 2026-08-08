#include <string>
#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int LIMIT = 100;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int response = 1;

        for (int i = 1; i < n; ++i) {
            response = response * (i + m - 1) / i;
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    cout << s.uniquePaths(3, 7) << '\n';
}
