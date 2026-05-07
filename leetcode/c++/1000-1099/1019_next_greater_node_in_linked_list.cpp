#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> nums;
        auto node = head;

        while (node != nullptr) {
            nums.push_back(node->val);
            node = node->next;
        }

        int n = static_cast<int>(nums.size());
        vector<int> response(n, 0);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                int index = st.top();
                st.pop();
                response[index] = nums[i];
            }

            st.push(i);
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums1 = {1, 2, 1}; const auto e: s.nextLargerNodes(nums1))
        cout << e << ' ';
    cout << '\n';

    for (vector<int> nums1 = {1, 2, 3, 4, 3}; const auto e: s.nextLargerNodes(nums1))
        cout << e << ' ';
    cout << '\n';
}
