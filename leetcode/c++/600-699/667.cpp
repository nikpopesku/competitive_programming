#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArray(const int n, const int k) {
        int left = 1, right = n;
        vector<int> response;

        for (int i = 0; i < k; ++i) {
            if (i % 2 == 1) {
                response.push_back(left++);
            } else {
                response.push_back(right--);
            }
        }

        if (k % 2 == 1) {
            for (int i = right; i >= left; --i) {
                response.push_back(i);
            }
        } else {
            for (int i = left; i <= right; ++i) {
                response.push_back(i);
            }
        }


        return response;
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
