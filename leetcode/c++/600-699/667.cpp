#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> v;
        backtrack(v, k, 0);
    }

private:
    vector<int> response;

    void backtrack(vector<int> v, int k, int n) {
        if (static_cast<int>(v.size()) == n && Solution::check(v) == k) {
            response = v;

            return;
        }
    }


    static int check(const vector<int> &v) {
        set<int> s;
        for (int i = 1; i < v.size(); ++i) {
            s.insert(abs(v[i] - v[i - 1]));
        }

        return s.size();
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
