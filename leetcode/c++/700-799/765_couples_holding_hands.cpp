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

        for (int i = 0; i < n; i += 2) {

        }
    }
};

int main() {
    auto s = Solution();

    vector<int> row = {0, 2, 1, 3};
    cout << s.minSwapsCouples(row) << endl;
}

}
