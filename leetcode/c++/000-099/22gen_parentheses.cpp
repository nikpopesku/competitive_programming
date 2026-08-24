#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return gen(1, n);
    }

private:
    void gen(int start, int end) {
        if (start > end) return;

        vector<string> combination{};

        for (int r = start; r <= end; ++r) {
            for (int i = 1; i <= r - 1; ++i) {

            }
        }
    }
};


int main() {
    auto s = Solution();

    vector nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(nums) << endl; //6

    vector nums2 = {4, 2, 0, 3, 2, 5};
    cout << s.trap(nums2) << endl;
}
