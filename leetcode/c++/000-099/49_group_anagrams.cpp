#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(const vector<string> &strs) {
        unordered_map<string, vector<string> > groupped_anagram;
        vector<vector<string> > groupped_anagram_vector;

        for (auto &st: strs) {
            string st_sorted = st;
            sort(st_sorted.begin(), st_sorted.end());
            groupped_anagram[st_sorted].push_back(st);
        }

        for (const auto& val: groupped_anagram | views::values) groupped_anagram_vector.push_back(val);

        return groupped_anagram_vector;
    }
};


int main() {
    auto s = Solution();

    for (vector<string> st = {"eat", "tea", "tan", "ate", "nat", "bat"}; auto &e: s.groupAnagrams(st)) {
        for (auto &x: e) cout << x << ' ';
        cout << '\n';
    }

    for (vector<string> st2 = {""}; auto &e: s.groupAnagrams(st2)) {
        for (auto &x: e) cout << x << ' ';
        cout << '\n';
    }

    for (vector<string> st3 = {""}; auto &e: s.groupAnagrams(st3)) {
        for (auto &x: e) cout << x << ' ';
        cout << '\n';
    }
    cout << '\n';
}
