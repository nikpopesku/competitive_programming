#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> response(n, 0);
        int cur_id = -1;
        int cur_start = -1;
        stack<int> st;

        for (auto &l: logs) {
            size_t first = l.find(':');
            size_t last = l.rfind(':');

            auto id = stoi(l.substr(0, first));
            auto operation = l.substr(first + 1, last - first - 1);
            int time = stoi(l.substr(last + 1));

            if (operation == "start") {
                if (cur_id != -1) {
                    response[cur_id] += time - cur_start;
                    st.push(cur_id);
                }
                cur_id = id;
                cur_start = time;
            } else {
                response[id] += time - cur_start + 1;
                if (!st.empty()) {
                    cur_id = st.top();
                    st.pop();
                    cur_start = time + 1;
                } else {
                    cur_id = -1;
                    cur_start = -1;
                }
            }
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    for (vector<string> logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"}; const auto e: s.exclusiveTime(2, logs))
        cout << e << ' ';
    
    cout << '\n';

    for (vector<string> logs2 = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"}; const auto e:
         s.exclusiveTime(1, logs2))
        cout << e << ' ';
    cout << '\n';

    for (vector<string> logs3 = {"0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"}; const auto e:
         s.exclusiveTime(2, logs3))
        cout << e << ' ';
    cout << '\n';
}
