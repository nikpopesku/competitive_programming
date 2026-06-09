#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int> &arr) {
        const int n = static_cast<int>(arr.size());
        vector<int> max_val = arr;
        vector conver(n, 0);
        conver[0] = 2 * arr[0];
        vector<long long> prefix_response(n);
        prefix_response = conver[0];

        for (int i = 1; i < n; ++i) {
            max_val[i] = max(max_val[i - 1], arr[i]);
            conver[i] = arr[i] + max_val[i];
            prefix_response[i] = prefix_response[i-1] + conver[i];
        }

        return prefix_response;
    }
};

int main() {
    auto sol = Solution();

    // [4,10,24,36,56]
    for (vector<int> nums{2, 3, 7, 5, 10}; const auto &e: sol.findPrefixScore(nums)) {
        cout << e << "\n";
    }
    // [2,4,8,16,32,64]
    for (vector<int> nums{1, 1, 2, 4, 8, 16}; const auto &e: sol.findPrefixScore(nums)) {
        cout << e << "\n";
    }
}
