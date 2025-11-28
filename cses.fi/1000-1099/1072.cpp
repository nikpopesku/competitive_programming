#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;

    for (int i = 1; i <= n; ++i) {
        mp[i] = 0;
    }

    vector<pair<int, int> > directions = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
    vector<pair<int, int> > directions2 = {{1, 2}, {2, 1}, {1, -2}, {2, -1}};
    int response = 0;

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            int count = 0;
            for (auto &[fst, snd]: directions2) {
                pair nd = {x + fst, y + snd};
                if (nd.first < n && nd.second >= 0 && nd.second < n) {
                    ++count;
                }
            }

            response += n * n - (x * n + y + 1 + count);
        }
    }

    cout << response << "\n";
}
