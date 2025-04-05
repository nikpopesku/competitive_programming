#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int const MAX = 10000000;

int main() {
    int N;

    cin >> N;

    cout << N << "\n";
    vector<int> q;

    q.push_back(N);

    map<int, bool> visited;
    visited[N] = true;

    int response = 0;
    int distance = 0;

    while (!q.empty() and response == 0) {
        ++distance;
        vector<int> new_q;

        for (auto & elem: q) {
            for (const auto & e: {elem - 1, elem + 1, elem * 2}) {
                if (e >= MAX) continue;

                if (!visited[e]) {
                    if (e == 0) {
                        response = distance;
                        break;
                    }
                    new_q.push_back(e);
                    visited[e] = true;
                }
            }
            if (response > 0) break;
            if (elem % 3 == 0) {
                while (elem % 3 == 0) {
                    elem /= 3;
                }

                if (!visited[elem]) {
                    new_q.push_back(elem);
                    visited[elem] = true;
                }
            }
        }


        q = new_q;
    }

    cout << response << "\n";
}
