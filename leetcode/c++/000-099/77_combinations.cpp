#include <print>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > combinations;

        vector<int> current_combination;
        backtrack(1, n, k, combinations, current_combination);

        return combinations;
    }

private:
    void backtrack(int start, const int n, const int k, vector<vector<int> > &combinations, vector<int> &current_combination) {
        if (current_combination.size() == k) {
            combinations.push_back(current_combination);

            return;
        }

        if (n - start + 1 < k) return;

        for (int i = start; i <= n; ++i) {
            current_combination.push_back(i);
            backtrack(i + 1, n, k, combinations, current_combination);
            current_combination.pop_back();
        }
    }
};

int main() {
    auto s = Solution();

    print("{}", s.combine(4, 2));
}
