#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        vector<int> left_count(n, 1);
        vector<int> right_count(n, 1);

        long long response = 0;

        for (int i = 0; i < n; ++i) {
            response = response + (static_cast<long long>(arr[i]) * left_count[i] * right_count[i]
        }

        return static_cast<int>(response);
    }
};

int main() {
    auto s = Solution();

    vector<int> arr = {3, 1, 2, 4};
    cout << s.sumSubarrayMins(arr) << endl; // Expected: 17

    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << s.sumSubarrayMins(arr2) << endl; // Expected: 444
}
