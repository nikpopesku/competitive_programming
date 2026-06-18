#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(const vector<int> &target) {
        priority_queue<int> pq;
        for (const auto &t: target) pq.push(-t);


    }
};


int main() {
    auto s = Solution();
    vector<int> target = {9, 3, 5};
    cout << boolalpha << s.isPossible(target) << '\n'; //true

    vector<int> target2 = {1, 1, 1, 2};
    cout << boolalpha << s.isPossible(target2) << '\n'; //false

    vector<int> target3 = {8, 5};
    cout << boolalpha << s.isPossible(target2) << '\n'; //true
}
