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

    vector st = {"eat","tea","tan","ate","nat","bat"};
    for (auto &e: s.groupAnagrams(st)) cout << e << ' ';
    cout << '\n';

    vector st2 = {""};
    for (auto &e: s.groupAnagrams(st2)) cout << e << ' ';
    cout << '\n';
}
