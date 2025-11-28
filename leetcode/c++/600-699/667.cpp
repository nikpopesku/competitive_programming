#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> v(n + 1, false);
        backtrack(v, k, 0, "");
    }

private:
    string response;

    void backtrack(vector<int> v, const int k, const int n, string s) {
        if (static_cast<int>(s.size()) == n && check(s) == k) {
            response = s;

            return;
        }

        if (check(s) > k) {
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (!v[i]) {
                v[i] = true;
                backtrack(v, k, n, s + to_string(i));
                v[i] = false;
            }
        }
    }


    static size_t check(const string &s) {
        set<int> ss;
        for (int i = 1; i < s.size(); ++i) {
            ss.insert(abs(s[i] - '0' - (s[i - 1] - '0')));
        }

        return ss.size();
    }
};

int main() {
    Solution s;

    int n, k;
    cin >> n >> k;

    for (const auto &e: s.constructArray(n, k)) {
        cout << e << " ";
    }

    return 0;
}
