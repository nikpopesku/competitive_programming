#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char> > pq;

        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});

        string response;

        while (!pq.empty()) {
            auto p1 = pq.top();
            pq.pop();

            if (pq.empty()) {
                response += p1.first > 1 ? p1.second + p1.second : p1.second;
                break;
            }

            auto p2 = pq.top();
            pq.pop();

            const int v1 = p1.first - 2 >= p2.first ? 2 : 1;
            response += v1 == 2 ? p1.second + p1.second : p1.second;

            const int v2 = p2.first - 2 >= pq.top().first ? 2 : 1;
            response += v2 == 2 ? p2.second + p2.second : p2.second;

            pq.push({p1.first - v1, p1.second});
            pq.push({p2.first - v2, p2.second});
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
