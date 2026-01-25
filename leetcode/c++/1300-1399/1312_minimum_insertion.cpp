#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {

    }
};
int main() {
    Solution s;

    cout << s.minInsertions("zzazz") << endl; //0
    cout << s.minInsertions("mbadm") << endl; //2
    cout << s.minInsertions("leetcode") << endl; //5

    return 0;
}
