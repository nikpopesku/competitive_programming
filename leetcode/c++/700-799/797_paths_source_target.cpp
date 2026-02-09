#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(const string& jewels, const string& stones) {
        unordered_set<int> s;

        for (const auto &j: jewels) {
            s.insert(j);
        }

        int counter = 0;

        for (const auto &st: stones) {
            if (s.contains(st)) {
                ++counter;
            }
        }

        return counter;
    }
};

int main() {
    auto s = Solution();
    cout << s.numJewelsInStones("aA", "aAAbbbb") << endl;
    cout << s.numJewelsInStones("z", "ZZ") << endl;
}
