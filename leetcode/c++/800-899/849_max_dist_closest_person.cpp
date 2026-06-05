#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(const vector<int> &seats) {
        int n = static_cast<int>(seats.size());
        int distance = 0;
        vector closest(n, 0);

        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                distance = 0;
            } else {
                closest[i] = ++distance;
            }
        }

        int max_distance = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (seats[i] == 1) {
                distance = 0;
            } else {
                closest[i] = min(closest[i], ++distance);
                max_distance = max(max_distance, closest[i]);
            }
        }

        return max_distance;
    }
};

int main() {
    auto s = Solution();

    vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
    cout << s.maxDistToClosest(seats) << endl; //2

    vector<int> seats2 = {1, 0, 0, 0};
    cout << s.maxDistToClosest(seats2) << endl; //3

    vector<int> seats3 = {0, 1};
    cout << s.maxDistToClosest(seats3) << endl; //1

    vector<int> seats4 = {0, 0, 1};
    cout << s.maxDistToClosest(seats4) << endl; //2

    vector<int> seats5 = {1, 0, 0};
    cout << s.maxDistToClosest(seats5) << endl; //2
}
