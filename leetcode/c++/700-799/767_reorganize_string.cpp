#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(const string &s) {
        unordered_map<char, int> mp;
        string response;
        response.reserve(s.size());

        for (auto &c: s) {
            ++mp[c];
        }

        priority_queue<pair<int, char> > pq;

        for (auto [fst, snd]: mp) {
            if (snd >= s.size() / 2 + 1) {
                return "";
            }

            pq.emplace(snd, fst);
        }


        while (!pq.empty()) {
            pair<int, char> first = {}, second = {};

            first = pq.top();
            response += first.second;
            pq.pop();


            if (pq.empty()) {
                break;
            }


            second = pq.top();
            pq.pop();
            response += second.second;

            if (--first.first > 0) {
                pq.emplace(first);
            }


            if (--second.first > 0) {
                pq.emplace(second);
            }
        }

        return response;
    }
};

int main() {
    Solution s;

    cout << s.reorganizeString("aab") << endl;
    cout << s.reorganizeString("aaab") << endl;

    return 0;
}
