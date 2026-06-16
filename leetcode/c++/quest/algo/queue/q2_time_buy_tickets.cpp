#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) {
    }
};

int main() {
    auto s = Solution();
    vector<int> tickets = {2, 3, 2};
    cout << s.timeRequiredToBuy(tickets, 2) << '\n'; //6

    vector<int> tickets2 = {5, 1, 1, 1};
    cout << s.timeRequiredToBuy(tickets2, 0) << '\n'; //8
}
