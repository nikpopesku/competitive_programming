#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    }
};


int main() {
    auto s = Solution();

    for (vector<string> st = {"eat","tea","tan","ate","nat","bat"}; auto &e: s.groupAnagrams(st)) {
        for (auto &x: e) cout << x << ' ';
    }
    cout << '\n';

    for (vector<string> st2 = {""}; auto &e: s.groupAnagrams(st2)) {
        for (auto &x: e) cout << x << ' ';
    }
    cout << '\n';

    for (vector<string> st3 = {""}; auto &e: s.groupAnagrams(st3)) {
        for (auto &x: e) cout << x << ' ';
    }
    cout << '\n';
}
