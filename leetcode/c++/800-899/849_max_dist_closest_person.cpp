#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
    }
};

int main() {
    auto s = Solution();

    vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
    cout << s.maxDistToClosest(seats) << endl; //2

    vector<int> seats2 = {1, 0, 0, 0};
    cout << s.maxDistToClosest(seats2) << endl; //2
}
