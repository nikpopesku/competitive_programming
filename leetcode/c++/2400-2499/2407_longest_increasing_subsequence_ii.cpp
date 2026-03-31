#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SegTree {
public:
    explicit SegTree(const int sz) : n(sz), tree(n * 4, 0) {
    }

    void update(const int pos, const int val) {
        update(1, 1, n, pos, val);
    }

    int query(const int l, const int r) {
        return query(1, 1, n, l, r);
    }

private:
    int n;
    vector<int> tree;

    void update(const int node, const int nl, const int nr, const int pos, const int val) {
        if (nl == nr) {
            tree[node] = max(tree[node], val);

            return;
        }

        if (const int mid = (nl + nr) / 2; mid <= pos) {
            update(node * 2, nl, mid, pos, val);
        } else {
            update(node * 2 + 1, mid + 1, nr, pos, val);
        }

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(const int node, const int nl, const int nr, const int l, const int r) {
        if (r < nl || l > nr) {
            return 0;
        }

        if (l <= nl && r >= nr) {
            return tree[node];
        }

        const int mid = (nl + nr) / 2;
        const int ans_left = query(node * 2, nl, mid, l, r);
        const int ans_right = query(node * 2 + 1, mid + 1, nl, l, r);

        return max(ans_left, ans_right);
    }
};

class Solution {
public:
    int lengthOfLIS(const vector<int> &nums, const int k) {
        SegTree st(100001);
        const int maxVal = *max_element(nums.begin(), nums.end());

        for (const int n: nums) {
            const int l = max(1, n - k);
            const int r = n - 1;

            int best = 0;

            if (r >= l) {
                best = st.query(l, r);
            }

            st.update(n, best + 1);
        }

        return st.query(1, maxVal);
    }
};

int main() {
    auto sol = Solution();

    // Example 1: expected 5  (subsequence 1->2->3->4->5 or 2->3->4->5->8 etc.)
    cout << sol.lengthOfLIS({4, 2, 1, 4, 3, 4, 5, 8, 15}, 3) << "\n";

    // Example 2: expected 4  (subsequence 1->3->5->7)
    cout << sol.lengthOfLIS({7, 4, 5, 1, 8, 12, 4, 7}, 5) << "\n";

    // Example 3: expected 1  (no two elements are within k=1 gap)
    cout << sol.lengthOfLIS({1, 5}, 1) << "\n";
}
