#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int> > &mat) {
    }
};

int main() {
    Solution s;

    vector<vector<int> > mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << s.numSubmat(mat) << endl; //13

    vector<vector<int> > mat2 = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
    cout << s.numSubmat(mat2) << endl; //24

    return 0;
}
