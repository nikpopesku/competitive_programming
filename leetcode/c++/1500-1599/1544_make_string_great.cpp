#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    string makeGood(const string &s) {
        vector<int> v;

        for (const auto &c: s) {
            if (!v.empty() && v.back() != c && (tolower(v.back()) == c || v.back() == tolower(c))) {
                v.pop_back();
            } else {
                v.push_back(c);
            }
        }

        string t(v.begin(), v.end());

        return t;
    }
};

int main() {
    Solution s;

    cout << s.makeGood("leEeetcode") << endl;
    cout << s.makeGood("abBAcC") << endl;
    cout << s.makeGood("s") << endl;

    return 0;
}
