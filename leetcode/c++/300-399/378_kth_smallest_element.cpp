#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> > &matrix, int k) {
    }
};

int main() {
    auto s = Solution();
    vector<vector<int> > matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << s.kthSmallest(matrix, 8) << endl; //13

    vector<vector<int> > matrix2 = {{-5}};
    cout << s.kthSmallest(matrix, 1) << endl; //-5
}
