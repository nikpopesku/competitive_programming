#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char> > pq;

        if (a > 0) {
            pq.emplace(a, 'a');
        }

        if (b > 0) {
            pq.emplace(b, 'b');
        }

        if (c > 0) {
            pq.emplace(c, 'c');
        }


        string response;

        while (!pq.empty()) {
            auto [i1, c1] = pq.top();
            pq.pop();

            if (pq.empty()) {
                response += c1;
                if (i1 > 1) {
                    response += c1;
                }
                break;
            }

            auto [i2, c2] = pq.top();
            pq.pop();

            const int v1 = i1 - 2 >= i2 ? 2 : 1;
            response += c1;
            if (v1 == 2) {
                response += c1;
            }

            const int v2 = !pq.empty() && i2 - 2 >= pq.top().first ? 2 : 1;
            response += c2;
            if (v2 == 2) {
                response += c2;
            }

            if (i1 - v1 > 0) {
                pq.emplace(i1 - v1, c1);
            }

            if (i2 - v2 > 0) {
                pq.emplace(i2 - v2, c2);
            }
        }

        return response;
    }
};

int main() {
    Solution s;

    cout << s.longestDiverseString(1, 1, 7) << endl;
    cout << s.longestDiverseString(7, 1, 0) << endl;
    cout << s.longestDiverseString(4, 42, 7) << endl; //bbcbbcbbcbbabbcbbabbcbbabbcbbabbcbb

    return 0;
}
