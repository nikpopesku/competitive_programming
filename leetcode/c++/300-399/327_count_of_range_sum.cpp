#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz): n(sz), tree(n+1) {

    }

    void update(int index) {
        ++index;
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }
private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int countRangeSum(const vector<int> &nums, const int lower, const int upper) {
        int pr = 0;
        vector prefix = {0LL};
        for (int x: nums) {
            pr += x;
            prefix.push_back(pr);
            prefix.push_back(pr - lower);
            prefix.push_back(pr - upper);
        }

        int answer = 0;

        return answer;
    }
};

int main() {
    auto na = Solution();

    vector v = {-2, 5, -1};
    cout << na.countRangeSum(v, -2, 2) << "\n";

    vector v2 = {0};
    cout << na.countRangeSum(v2, 0, 0) << "\n";
}
