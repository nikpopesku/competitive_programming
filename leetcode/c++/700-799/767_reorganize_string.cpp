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

        for (auto elem: mp) {
            if (elem.second > s.size() / 2 + 1) {
                return "";
            }

            pq.emplace(elem);
        }


        while (!pq.empty()) {
            pair<char, int> first = {}, second = {};

            first = pq.top();
            response += first.first;
            pq.pop();


            if (pq.empty()) {
                break;
            }


            second = pq.top();
            pq.pop();
            response += second.first;

            if (--first.second > 0) {
                pq.emplace(first);
            }


            if (--second.second > 0) {
                pq.emplace(second);
            }
        }
    }
};

int main() {
    Solution s;

    cout << s.reorganizeString("aab") << endl;
    cout << s.reorganizeString("aaab") << endl;

    return 0;
}
