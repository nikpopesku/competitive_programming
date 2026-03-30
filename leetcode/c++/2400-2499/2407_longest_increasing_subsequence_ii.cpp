#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Segment tree over the VALUE domain [1, maxVal].
// Each node stores the max dp value (longest valid subsequence length)
// for any value in its range.
// Supports:
//   - point update:  store dp at a specific value
//   - range max query: max dp over a value range [l, r]
class SegTree {
public:
    explicit SegTree(const int sz) : n(sz), tree(4 * sz, 0) {
    }

    // Update position pos with val (take max, not overwrite —
    // same value can appear multiple times, keep the best dp)
    void update(const int pos, const int val) {
        update(1, 1, n, pos, val);
    }

    // Return max dp value in value range [l, r]
    [[nodiscard]] int query(const int l, const int r) const {
        return query(1, 1, n, l, r);
    }

private:
    int n;
    vector<int> tree;

    void update(const int node, const int nL, const int nR, const int pos, const int val) {
        // Reached the leaf for exactly this value
        if (nL == nR) {
            tree[node] = max(tree[node], val);
            return;
        }

        const int mid = (nL + nR) / 2;

        if (pos <= mid)
            update(node * 2, nL, mid, pos, val);
        else
            update(node * 2 + 1, mid + 1, nR, pos, val);

        // Pull up: this node's max = best of its two children
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    [[nodiscard]] int query(const int node, const int nL, const int nR, const int l, const int r) const {
        // This node's range is completely outside the query range
        if (r < nL || nR < l)
            return 0;

        // This node's range is completely inside the query range
        if (l <= nL && nR <= r)
            return tree[node];

        // Partial overlap: recurse into both children
        const int mid = (nL + nR) / 2;
        const int leftAns  = query(node * 2,     nL,    mid, l, r);
        const int rightAns = query(node * 2 + 1, mid+1, nR,  l, r);
        return max(leftAns, rightAns);
    }
};

class Solution {
public:
    int lengthOfLIS(const vector<int> &nums, const int k) {
        const int maxVal = *max_element(nums.begin(), nums.end());
        SegTree st(maxVal);

        for (const int v : nums) {
            // Valid predecessors must have value in [v-k, v-1]:
            //   - strictly less than v  (strictly increasing)
            //   - at most k apart       (gap constraint)
            const int l = max(1, v - k);
            const int r = v - 1;

            // best = longest chain we can extend; 0 if no valid predecessor
            const int best = (r >= l) ? st.query(l, r) : 0;

            // Extend the best predecessor chain, or start fresh (0+1=1)
            st.update(v, best + 1);
        }

        // Global max dp across all values
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
