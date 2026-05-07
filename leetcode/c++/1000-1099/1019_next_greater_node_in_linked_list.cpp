#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums1 = {1, 2, 1}; const auto e: s.nextGreaterElements(nums1))
        cout << e << ' ';
    cout << '\n';

    for (vector<int> nums1 = {1, 2, 3, 4, 3}; const auto e: s.nextGreaterElements(nums1))
        cout << e << ' ';
    cout << '\n';
}
