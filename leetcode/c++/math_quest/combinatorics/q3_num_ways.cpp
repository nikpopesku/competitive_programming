#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= min(n, k); ++i) {
            dp[i][i] = 1;
        }
    }
};

int main() {
    auto s = Solution();

    cout << s.rearrangeSticks(3, 2) << '\n';
}
