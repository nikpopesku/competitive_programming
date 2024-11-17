#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>


using std::cout, std::endl, std::vector, std::sort, std::max;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), myfunction);
        vector<int> height {};

        for (size_t i = 0; i < envelopes.size(); i++) {
            height.push_back(envelopes[i][1]);
        }

        vector<int>dp {};


        for (size_t i = 0; i < height.size(); i++) {
            auto lower = lower_bound(dp.begin(), dp.end(), height[i]);
            if (lower == dp.end) {
                dp.push_back(height[i]);
            } else {
                dp[lower-dp.begin()] = height[i];
            }

        }


        return dp.size();
    }
private:
    static bool myfunction (const vector<int> &i, const vector<int> &j) {
        if (i[0] < j[0]) {
            return true;
        }
        if (j[0] > i[0]) {
            return true;
        }

        if (i[1] > j[1]) {
            return true;
        }

        return false;
    }
};

int main() {
    auto s = Solution();
    auto a = vector{vector<int>{5,4},vector<int>{6,4},vector<int>{6,7},vector<int>{2,3}};
    cout << s.maxEnvelopes(a) << endl;
}
