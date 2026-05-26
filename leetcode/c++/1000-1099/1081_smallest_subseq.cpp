#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<char> v;
        unordered_map<char, int> last_occurrence;
        set<char> st;
        int n = static_cast<int>(s.size());

        for (int i = 0; i < n; ++i) {
            last_occurrence[s[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            if (st.contains(s[i])) continue;

            while (!v.empty() && v.back() > s[i] && last_occurrence[v.back()] > i) {
                st.erase(v.back());
                v.pop_back();
            }

            st.insert(s[i]);
            v.push_back(s[i]);
        }


        string ss(v.begin(), v.end());

        return ss;
    }
};

int main() {
    Solution s;

    cout << s.smallestSubsequence("bcabc") << endl; //abc
    cout << s.smallestSubsequence("cbacdcbc") << endl; //acdb

    return 0;
}
