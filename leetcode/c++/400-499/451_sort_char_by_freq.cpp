#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <unordered_map>


using namespace std;

class Solution {
public:
    string frequencySort(const string& s) {
        unordered_map<char, int> freq;
        map<int, set<char> > mp;

        for (auto &c: s) {
            ++freq[c];
        }

        for (auto &[c, f]: freq) {
            mp[f].insert(c);
        }

        string ss;

        for (auto &[fst, snd] : std::ranges::reverse_view(mp)) {
            for (auto &c: snd) {
                for (int i = 0; i < fst; ++i) {
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
