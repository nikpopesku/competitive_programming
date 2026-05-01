#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
    }
};

int main() {
    auto s = Solution();

    for (vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"}; const auto e: s.exclusiveTime(2, logs))
        cout << e << ' ';
    cout << '\n';

    for (vector<string> logs2 = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"}; const auto e:
         s.exclusiveTime(1, logs2)) cout << e << ' ';
    cout << '\n';
}
