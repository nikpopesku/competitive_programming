#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::endl, std::vector, std::sort;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), myfunction);

    }
private:
    static bool myfunction (vector<int> i,vector<int> j) { return (i[0] + i[1]) < (j[0] + j[1]); }
};

int main() {
    auto s = Solution();
    auto a = vector{vector<int>{5,4},vector<int>{6,4},vector<int>{6,7},vector<int>{2,3}};
    cout << s.maxEnvelopes(a) << endl;
}
