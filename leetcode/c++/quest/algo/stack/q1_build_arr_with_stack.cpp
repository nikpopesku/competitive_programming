#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int> &target, int n) {
        int j = 0;
        vector<string> response;
        int m = static_cast<int>(target.size());

        for (int i = 1; i <= n; ++i) {
            if (j == m) break;
            response.push_back("Push");
            if (i != target[j]) {
                response.push_back("Pop");
            } else {
                ++j;
            }
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {1, 3}; const auto e: s.buildArray(nums, 3)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {1, 2, 3}; const auto e: s.buildArray(nums, 3)) cout << e << ' ';
    cout << '\n';
}
