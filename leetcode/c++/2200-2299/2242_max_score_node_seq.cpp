#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {

    }
};

int main() {
    auto s = Solution();

    vector<int> scores = {5,2,9,8,4};
    vector<vector<int> > edges = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    cout << s.maximumScore(scores, edges) << endl; //0
}
