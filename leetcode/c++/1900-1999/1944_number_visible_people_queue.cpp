#include <iostream>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int> &heights) {
    }
};

int main() {
    auto s = Solution();

    vector<int> heights = {10, 6, 8, 5, 11, 9};
    for (auto id: s.canSeePersonsCount(heights))
        cout << id << endl;

    vector<int> heights2 = {5, 1, 2, 3, 10};
    for (auto id: s.canSeePersonsCount(heights2))
        cout << id << endl;
}
