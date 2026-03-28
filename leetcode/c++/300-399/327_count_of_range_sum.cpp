#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit (const int sz): n(sz), tree(sz + 1, 0) {

    }

    void update(int index) {
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }

    [[nodiscard]] int range(const int a, const int b) const {
        return query(b) - query(a -1);
    }

    [[nodiscard]] int query(int index) const {
        int sm = 0;
        while (index > 0) {
            sm += tree[index];
            index -= index & -index;
        }

        return sm;
    }
private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int countRangeSum(const vector<int> &nums, const int lower, const int upper) {
        vector<int> prefix;
        for (int x: nums) {
            prefix.push_back(x);
            prefix.push_back(x - lower);
            prefix.push_back(x - upper);
        }

        sort(prefix.begin(), prefix.end());
        prefix.erase(unique(prefix.begin(), prefix.end()), prefix.end());
        const int n = static_cast<int>(nums.size());
        const int m = static_cast<int>(prefix.size());
        Bit bt(m);
        bt.update(prefix[0]);

        int answer = 0;

        for (int j = 0; j < n; ++j) {
            const int index = static_cast<int>(lower_bound(prefix.begin(), prefix.end(), nums[j]) - prefix.begin());
            const int a = prefix[index] - upper;
            const int b = prefix[index] - lower;
            const int rank_a = static_cast<int>(lower_bound(prefix.begin(), prefix.end(), a) - prefix.begin());
            const int rank_b = static_cast<int>(lower_bound(prefix.begin(), prefix.end(), b) - prefix.begin());

            answer += bt.range(rank_a, rank_b);
            bt.update(j);
        }

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
