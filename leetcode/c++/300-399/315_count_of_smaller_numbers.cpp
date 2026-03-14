#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

    [[nodiscard]] int query(int index) const {
        int response = 0;

        while (index > 0) {
            response += tree[index];
            index -= index & -index;
        }

        return response;
    }


    void update(int index) {
        while (index <= n) {
            tree[index]++;
            index += index & -index;
        }
    }

private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    vector<int> countSmaller(const vector<int> &nums) {
        Bit bt(20001);
        const int n = static_cast<int>(nums.size());
        vector<int> response(n, 0);

        for (int i = n - 1; i >= 0; --i) {
            const int val = nums[i] + 10000;
            response[i] = bt.query(i);
            bt.update(val - 1);
        }

        return response;
    }
};


int main() {
    const vector nums = {5, 2, 6, 1};
    for (auto na = Solution(); const auto &i: na.countSmaller(nums)) {
        cout << i << "\n";
    }
}
