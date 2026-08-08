#include <string>
#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int LIMIT = 100;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int response = 1;
        set<int> st;
        for (int i = 2; i < n; ++i) st.insert(i);

        for (int i = m; i <= m + n - 2; ++i) {
            response *= i;
            vector<int> dividers{};
            for (auto &elem: st) {
                if (response % elem == 0) {
                    response /= elem;
                    dividers.push_back(elem);
                }
            }
            for (auto &elem: dividers) st.erase(elem);
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    cout << s.uniquePaths(3, 7) << '\n';
}
