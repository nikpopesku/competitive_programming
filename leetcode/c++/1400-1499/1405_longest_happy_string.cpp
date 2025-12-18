#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char> > pq;

        pq.emplace(a, 'a');
        pq.emplace(b, 'b');
        pq.emplace(c, 'c');

        string response;

        while (!pq.empty()) {
            auto [i1, c1] = pq.top();
            pq.pop();

            if (pq.empty()) {
                response += i1 > 1 ? c1 + c1 : c1;
                break;
            }

            auto [i2, c2] = pq.top();
            pq.pop();

            const int v1 = i1 - 2 >= i2 ? 2 : 1;
            response += v1 == 2 ? c1 + c1 : c1;

            const int v2 = i2 - 2 >= pq.top().first ? 2 : 1;
            response += v2 == 2 ? c2 + c2 : c2;

            pq.emplace(i1 - v1, c1);
            pq.emplace(i2 - v2, c2);
        }

        return response;
    }
};

int main() {
    Solution s;

    cout << s.longestDiverseString(1, 1, 7) << endl;
    cout << s.longestDiverseString(7, 1, 0) << endl;

    return 0;
}
