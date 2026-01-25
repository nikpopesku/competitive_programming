#include <algorithm>
#include <complex>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, const int k) {
        vector<pair<char, int>> v;

        for (auto& c: s) {
            if (!v.empty() && v.back().first == c) {
                auto [fst, snd] = v.back();
                v.pop_back();

                if (snd + 1 < k) {
                    v.emplace_back(fst, snd + 1);
                }
            } else {
                v.emplace_back(c, 1);
            }
        }

        string response;

        for (auto &[fst, snd]: v) {
            for (int i = 0; i < snd; ++i) {
                response += fst;
            }
         }


        return response;
    }
};

int main() {
    Solution s;

    cout << s.removeDuplicates("abcd", 2) << endl; //abcd
    cout << s.removeDuplicates("deeedbbcccbdaa", 3) << endl; //aa
    cout << s.removeDuplicates("pbbcggttciiippooaais", 2) << endl; //ps

    return 0;
}
