#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for (auto &c: s) {
            ++mp[c];
        }

        priority_queue<pair<int, char> > pq;

        for (auto it: mp) {
            pq.push(*it);
        }
    }
};

int main() {
    Solution s;

    cout << s.reorganizeString("aab") << endl;
    cout << s.reorganizeString("aaab") << endl;

    return 0;
}
