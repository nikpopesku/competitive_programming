#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    Bit(int sz): n(sz), tree(sz+1, 0) {}

    void update(int index) {

    }

    int query(int index) {
        int response = 0;

        while (index > 0) {
            response += tree[index];
            index -= index & -index;
        }

        return response;
    }
private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int reversePairs(vector<int> &nums) {
    }
};


int main() {
    vector nums = {1, 3, 2, 3, 1};
    auto na = Solution();
    cout << na.reversePairs(nums) << "\n";
}
