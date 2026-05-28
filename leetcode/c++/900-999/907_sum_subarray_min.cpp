#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(const vector<int> &arr) {
        const int n = static_cast<int>(arr.size());
        vector<int> mn_right(n + 1, 0);
        vector<int> mn_left(n, 0);
        mn_left[0] = arr[0];

        for (int i = n - 1; i >= 0; --i) {
            mn_right[i] = min(mn_right[i + 1], arr[i]);
        }

        for (int i = 1; i < n; ++i) {
            mn_left[i] = min(mn_left[i], arr[i]);
        }
    }
};

int main() {
    auto s = Solution();

    vector<int> arr = {3, 1, 2, 4};
    cout << s.sumSubarrayMins(arr) << endl; // Expected: 17

    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << s.sumSubarrayMins(arr2) << endl; // Expected: 444
}
