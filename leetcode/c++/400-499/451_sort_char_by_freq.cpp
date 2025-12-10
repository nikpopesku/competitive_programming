#include <iostream>
#include <map>
#include <set>
#include <unordered_map>


using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        map<int, set<char> > mp;

        for (auto &c: s) {
            ++freq[c];
        }

        for (auto &[c, f]: freq) {
            mp[f].insert(c);
        }

        string ss;

        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            for (auto &c: it->second) {
                for (int i = 0; i < it->first; ++i) {
                    ss += c;
                }
            }
        }

        return ss;
    }
};

int main() {
    auto s = Solution();
    cout << s.frequencySort("tree") << endl;
    cout << s.frequencySort("cccaaa") << endl;
    cout << s.frequencySort("Aabb") << endl;
}
