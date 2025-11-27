#include <iostream>
#include <numeric>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        set s(v.begin(), v.end());

        backtrack(1, n, s);

        return response;
    }

private:
    int response = 1;

    void backtrack(const int index, const int n, set<int> s) {
        if (s.empty()) {
            ++response;
        }

        for (int k = 1; k <= index; ++k) {
            if (index % k == 0 && s.count(k) != 0) {
                s.erase(k);
                backtrack(index + 1, n, s);
            }
        }
    }
};

int main() {
    Solution s;

    int n;
    cin >> n;

    cout << s.countArrangement(n);
}
