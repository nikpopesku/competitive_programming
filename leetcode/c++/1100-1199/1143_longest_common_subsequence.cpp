#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution1 {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) {
        return calc(text1, text2).size();
    }
private:
    string calc(const string &s1, const string &s2) {
        static const string empty {};
        if (s1.empty() or s2.empty()) return empty;
        const string key = s1 + "_" + s2;
        if (dp.find(key) != dp.end()) return dp[key];

        if (s1[0] != s2[0]) {
            auto r1 = calc(s1.substr(1, s1.size() - 1), s2);
            auto r2 = calc(s1, s2.substr(1, s2.size() - 1));

            if (r1.size() > r2.size()) {
                return r1;
            }

            return r2;
        }

        dp[key] = s1[0] + calc(s1.substr(1, s1.size() - 1), s2.substr(1, s2.size() - 1));

        return dp[key];
    }

    unordered_map<string, string> dp {};
};


class Solution2 {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) {
        vector dp (text1.size()+1, vector<unsigned long long> (text2.size() + 1, 0));
        dp[0][0] = 0;

        for (auto i = 1; i <= text1.size(); i++) {
            for (auto j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];

    }
};


int main() {
    auto s = Solution2();
    cout << s.longestCommonSubsequence("ylqpejqbalahwr", "yrkzavgdmdgtqpg") << endl;
}
