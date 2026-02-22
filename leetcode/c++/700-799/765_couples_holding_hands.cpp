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
            mp[row[i]] = i;
        }

        int counter = 0;

        for (int i = 0; i < n; i += 2) {
            int couple_nei = row[i] % 2 == 0 ? row[i] + 1 : row[i] - 1;
            if (abs(mp[row[i]] - mp[couple_nei]) > 1) {
                ++counter;
                int temp = row[i+1];
                int new_position = mp[couple_nei];
                swap(row[mp[couple_nei]], row[i+1]);
                mp[temp] = new_position;
            }
        }

        return counter;
    }
};

int main() {
    auto s = Solution();

    vector<int> row = {0, 2, 1, 3}; //1
    cout << s.minSwapsCouples(row) << endl;

    vector<int> row2 = {3, 2, 0, 1}; //0
    cout << s.minSwapsCouples(row2) << endl;
}
