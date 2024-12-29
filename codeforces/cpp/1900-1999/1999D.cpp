#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

int main() {
    int tt;
    std::string s, t;
    std::cin >> tt;


    for (auto i = 0; i < tt; i++) {
        std::cin >> s;
        std::cin >> t;

        std::vector dp(s.size() + 1, std::vector<int> (t.size() + 1, INT_MAX));
        for (auto col = 0; col <= s.size(); col++) dp[0][col] = 0;


        for (auto row = 1; row <= t.size(); row++) {
            for (auto col = 1; col <= s.size(); col++) {
                int value = INT_MAX;
                if (s[row-1] == t[col-1]) value = dp[row-1][col-1] + 1;
                if (s[row-1] == '?') value = dp[row-1][col-1] + 1;

                std::vector temp {value, dp[row][col-1], dp[row-1][col]};
                dp[row][col] = *std::min_element(temp.begin(), temp.end());
            }
        }

        if (dp[s.size()][t.size()] < INT_MAX) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }



    }
}
