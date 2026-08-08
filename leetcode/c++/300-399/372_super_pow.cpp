#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int superPow(int a, vector<int> &b) {
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
