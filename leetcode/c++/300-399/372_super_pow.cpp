#include <iostream>
#include <vector>


using namespace std;

constexpr int MD = 1337;

class Solution {
public:
    int superPow(int a, vector<int> &b) {
        int res = 1;


        for (int & i : b) {
            for (auto val: {10, i}) {
                while (val > 0) {
                    if (val & 1) {
                        res = res * val % MD;
                        --val;
                    } else {
                        val >>= 1;
                        res = res * res % MD;
                    }
                }
            }
        }


        return res;
    }
};

int main() {
    auto s = Solution();
    vector<int> v{3};
    std::cout << s.superPow(2, v) << std::endl;

    vector<int> v2{1, 0};
    std::cout << s.superPow(2, v2) << std::endl;

    vector<int> v3{4, 3, 3, 8, 5, 2};
    std::cout << s.superPow(1, v3) << std::endl;
}
