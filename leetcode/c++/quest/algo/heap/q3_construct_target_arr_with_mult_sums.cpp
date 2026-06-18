#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(const vector<int> &target) {
        priority_queue<pair<int, int> > pq;
        const int n = static_cast<int>(target.size());

        for (int i = 0; i < n; ++i) {
            pq.emplace(-target[i], i);
        }

        vector<int> arr(n, 1);
        int current_sum = n;
        int previous_diff = 0;

        while (!pq.empty()) {
            int elem = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            if (elem == -1) continue;

            if (current_sum > -elem) {
                return false;
            }

            if (current_sum <= -elem) {
                const int temp = arr[i];
                arr[i] = current_sum;
                current_sum = 2 * current_sum - temp;
                if (current_sum - arr[i] == previous_diff) {
                    if ((-elem - arr[i]) % previous_diff != 0) {
                        return false;
                    }

                    current_sum = -elem;
                } else {
                    previous_diff = current_sum - arr[i];

                    if (current_sum < -elem) {
                        pq.emplace(elem, i);
                    }
                }
            }
        }

        return true;
    }
};


int main() {
    auto s = Solution();
    // vector<int> target = {9, 3, 5};
    // cout << boolalpha << s.isPossible(target) << '\n'; //true
    //
    // vector<int> target2 = {1, 1, 1, 2};
    // cout << boolalpha << s.isPossible(target2) << '\n'; //false
    //
    // vector<int> target3 = {8, 5};
    // cout << boolalpha << s.isPossible(target3) << '\n'; //true
    //
    // vector<int> target4 = {1, 1000000000};
    // cout << boolalpha << s.isPossible(target4) << '\n'; //true
    //
    // vector<int> target5 = {1};
    // cout << boolalpha << s.isPossible(target5) << '\n'; //true

    vector<int> target6 = {2};
    cout << boolalpha << s.isPossible(target6) << '\n'; //true
}
