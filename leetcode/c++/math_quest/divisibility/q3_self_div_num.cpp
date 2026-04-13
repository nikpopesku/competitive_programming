#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> response;

        for (int ce = left; ce <= right; ++ce) {
            int e = ce;
            bool flag = true;
            while (e) {
                const int digit = e % 10;
                if (digit == 0) {
                    flag = false;
                    break;
                }
                if (ce % digit != 0) {
                    flag = false;
                    break;
                }
                e /= 10;
            }

            if (flag) {
                response.push_back(ce);
            }
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    for (auto e: s.selfDividingNumbers(1, 22)) {
        cout << e << ' ';
    }
}
