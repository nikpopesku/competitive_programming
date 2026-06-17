#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > kSmallestPairs(const vector<int> &nums1, const vector<int> &nums2, int k) {
        priority_queue<pair<int, vector<int> > > pq;

        for (const auto &n1: nums1) {
            for (const auto &n2: nums2) {
                pq.push({-n1 - n2, vector{n1, n2}});
            }
        }

        vector<vector<int> > pairs_with_smallest_sum;

        for (int i = 0; i < k; ++i) {
            pairs_with_smallest_sum.push_back(pq.top().second);
            pq.pop();
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
