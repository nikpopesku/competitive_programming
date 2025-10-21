#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> mp;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mp[a[i]] += 1;
        }

        for (auto &elem: mp) {
            if (elem.second % k != 0) {
                cout << "0\n";

                continue;
            }
        }
    }

    return 0;
}
