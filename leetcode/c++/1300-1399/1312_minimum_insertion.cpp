#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        vector dp(n, vector(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
    }
};

int main() {
    Solution s;

    cout << s.minInsertions("zzazz") << endl; //0
    cout << s.minInsertions("mbadm") << endl; //2
    cout << s.minInsertions("leetcode") << endl; //5

    return 0;
}
