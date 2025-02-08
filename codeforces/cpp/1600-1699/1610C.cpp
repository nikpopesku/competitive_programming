#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool calc(int k, vector<int> &vc_a, vector<int> &vc_b) {
    int count = 0;
    std::set<int> s_b;

    for (int i = 0; i < vc_b.size(); ++i) {
        if (vc_b[i] >= count and count < k) count++;
        else s_b.insert(i);
    }

    if (count < k) return false;
    count = k;

    for (int i = 0; i < vc_a.size(); ++i) {
        if (vc_a[i] >= count - 1 and count > 0 and s_b.count(i) == 0) --count;
    }

    return count == 0;
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n;

        vector<int> vc_a(n);
        vector<int> vc_b(n);

        for (int j = 0; j < n; ++j) {
            cin >> vc_a[j] >> vc_b[j];
        }

        int left = 1, right = n;

        while (left < right) {
            int m = left + (right - left + 1) / 2;

            bool value = calc(m, vc_a, vc_b);
            if (value) {
                left = m;
            } else {
                right = m - 1;
            }
        }

        cout << left << endl;
    }
}
