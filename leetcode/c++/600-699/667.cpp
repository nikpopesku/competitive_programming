#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void constructArray(const int n, const int k) {
        const vector<int> v(n + 1, false);
        backtrack(v, k, n, "");
    }

    string response;

private:
    void backtrack(vector<int> v, const int k, const int n, const string& s) {
        if (static_cast<int>(s.size()) == n) {
            if (check(s) == k) {
                response = s;
            }

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

    s.constructArray(n, k);

    for (const auto &c: s.response) {
        cout << c << " ";
    }

    return 0;
}
