#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > kSmallestPairs(const vector<int> &nums1, const vector<int> &nums2, int k) {
        priority_queue<tuple<int, int, int> > pq;

        for (int i = 0; i < static_cast<int>(nums1.size()); ++i) pq.emplace(-nums1[i] - nums2[0], i, 0);
        vector<vector<int> > pairs_with_smallest_sum;

        for (int i = 0; i < k; ++i) {
            const int n1 = get<1>(pq.top());
            const int n2 = get<2>(pq.top());
            pairs_with_smallest_sum.push_back(vector{nums1[n1], nums2[n2]});
            pq.pop();
            if (i < k - 1) {
                pq.emplace(-nums1[n1] - nums2[n2 + 1], n1, n2 + 1);
            }
        }

        return pairs_with_smallest_sum;
    }
};

int main() {
    auto s = Solution();
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    for (auto &x: s.kSmallestPairs(nums1, nums2, 3)) {
        for (const auto &y: x) cout << y << ' ';
        cout << '\n';
    }
    cout << '\n';
    cout << '\n';

    vector<int> nums12 = {1, 1, 2};
    vector<int> nums22 = {1, 2, 3};
    for (auto &x: s.kSmallestPairs(nums12, nums22, 2)) {
        for (const auto &y: x) cout << y << ' ';
        cout << '\n';
    }
    cout << '\n';
}
