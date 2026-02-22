#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

    }
};

int main() {
    auto s = Solution();

    vector<int> row = {0, 2, 1, 3}; //1
    cout << s.minSwapsCouples(row) << endl;

    vector<int> row2 = {3, 2, 0, 1}; //0
    cout << s.minSwapsCouples(row2) << endl;
}
