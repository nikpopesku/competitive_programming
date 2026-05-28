#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(const vector<int> &arr) {
        const int n = static_cast<int>(arr.size());
        vector<int> mn(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            mn[i] = min(mn[i + 1], arr[i]);
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
