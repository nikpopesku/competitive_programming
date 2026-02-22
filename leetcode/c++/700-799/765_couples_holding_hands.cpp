#include <complex>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        unordered_map<int, int> mp;
        int n = static_cast<int>(row.size());

        for (int i = 0; i < n; ++i) {
            mp[row[i]]  = i;
        }

        int counter = 0;

        for (int i = 0; i < n; i += 2) {
            if (abs(mp[i] - mp[i+1]) > 1) {
                ++counter;
            }
        }

        return counter;
    }
};

int main() {
    auto s = Solution();

    vector<int> row = {0, 2, 1, 3}; //1
    cout << s.minSwapsCouples(row) << endl;

    vector<int> row2 = {3,2,0,1}; //0
    cout << s.minSwapsCouples(row2) << endl;
}
