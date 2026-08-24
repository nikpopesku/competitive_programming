#include <string>
#include <print>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combination{};
        gen(n, n, combination, "");

        return combination;
    }

private:
    void gen(const int left, const int right, vector<string> &combination, const string &cur_comb) {
        if (left > right) return;

        if (left == 0 && right == 0) {
            combination.push_back(cur_comb);

            return;
        }


        if (left > 0) {
            gen(left - 1, right, combination, cur_comb + '(');
        }

        gen(left, right - 1, combination, cur_comb + ')');
    }
};


int main() {
    auto s = Solution();

    print("{}\n", s.generateParenthesis(3));
    print("{}\n", s.generateParenthesis(1));
}
