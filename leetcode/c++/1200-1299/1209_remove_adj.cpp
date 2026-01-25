#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {

    }
};

int main() {
    Solution s;

    cout << s.removeDuplicates("abcd", 2) << endl; //abcd
    cout << s.removeDuplicates("deeedbbcccbdaa", 3) << endl; //aa
    cout << s.removeDuplicates("pbbcggttciiippooaais", 2) << endl; //ps

    return 0;
}
