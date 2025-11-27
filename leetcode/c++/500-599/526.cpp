#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        unordered_map<int, set<int> > mp = {
            {1, {1}},
            {2, {1, 2}},
            {3, {1, 3}},
            {4, {1, 2, 4}},
            {5, {1, 5}},
            {6, {1, 2, 3, 6}},
            {7, {1, 7}},
            {8, {1, 2, 4, 8}},
            {9, {1, 3, 9}},
            {10, {1, 2, 5, 10}},
            {11, {1, 11}},
            {12, {1, 2, 3, 4, 6, 12}},
            {13, {1, 13}},
            {14, {1, 2, 7, 14}},
            {15, {1, 3, 5, 15}},
        };

        int response = 1;

        for (int i = 1; i <= n; ++i) {
            response *= static_cast<int>(mp[i].size());
        }

        return response;
    }
};

int main() {
    Solution s;

    int n;
    cin >> n;

    cout << s.countArrangement(n);
}