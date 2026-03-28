#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

    void update(int index) {
        ++index;
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }

    [[nodiscard]] int range(const int a, const int b) const {
        return query(b + 1) - query(a);
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
        vector prefix = {0LL};
        long long pr = 0;
        for (const int x: nums) {
            pr += x;
            prefix.push_back(pr);
            prefix.push_back(pr - lower);
            prefix.push_back(pr - upper);
        }

        sort(prefix.begin(), prefix.end());
        prefix.erase(unique(prefix.begin(), prefix.end()), prefix.end());
        const int n = static_cast<int>(nums.size());
        const int m = static_cast<int>(prefix.size());
        Bit bt(m);
        bt.update(static_cast<int>(lower_bound(prefix.begin(), prefix.end(), 0) - prefix.begin()));
        int answer = 0;

        pr = 0;
        for (int j = 0; j < n; ++j) {
            pr += nums[j];
            const long long a = pr - upper;
            const long long b = pr - lower;
            const int rank_a = static_cast<int>(lower_bound(prefix.begin(), prefix.end(), a) - prefix.begin());
            const int rank_b = static_cast<int>(upper_bound(prefix.begin(), prefix.end(), b) - prefix.begin()) - 1;

            if (rank_a <= rank_b) {
                answer += bt.range(rank_a, rank_b);
            }

            const int rank_pr = static_cast<int>(lower_bound(prefix.begin(), prefix.end(), pr) - prefix.begin());
            bt.update(rank_pr);
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
