#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int countArrangement(const int n) {
        used = vector(n + 1, false);
        backtrack(1, n);

        return response;
    }

    int response = 0;
    vector<bool> used;
private:
    void backtrack(const int index, const int n) {
        if (index > n) {
            ++response;

            return;
        }

        for (int num = 1; num <= n; ++num) {
            if (!used[num] && (num % index == 0 || index % num == 0)) {
                used[num] = true;
                backtrack(index + 1, n);
                used[num] = false;
            }
        }
    }
};

int main() {
    Solution s;

    int n;
    cin >> n;

    cout << s.countArrangement(n);
    return 0;
}