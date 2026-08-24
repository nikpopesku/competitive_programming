#include <string>
#include <iostream>
#include <stack>
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

    vector nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(nums) << endl; //6

    vector nums2 = {4, 2, 0, 3, 2, 5};
    cout << s.trap(nums2) << endl;
}
