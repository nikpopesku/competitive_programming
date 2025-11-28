#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArray(const int n, const int k) {
        vector<int> result;
        int left = 1, right = n;

        // Create k distinct differences by alternating
        for (int i = 0; i < k; ++i) {
            if (i % 2 == 0) {
                result.push_back(left++);
            } else {
                result.push_back(right--);
            }
        }

        // Fill remaining with monotonic sequence
        if (k % 2 == 0) {
            for (int i = right; i >= left; --i) {
                result.push_back(i);
            }
        } else {
            for (int i = left; i <= right; ++i) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    int n, k;
    cin >> n >> k;

    for (const auto &c: s.constructArray(n, k)) {
        cout << c << " ";
    }

    return 0;
}
