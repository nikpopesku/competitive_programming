#include <print>
#include <vector>

using namespace std;

#define ull unsigned long long

class Solution {
public:
    int numTrees(int n) {
        vector<ull> fact(2 * n + 1, 1);

        for (ull i = 2; i < fact.size(); ++i) {
            fact[i] = i * fact[i];
        }
    }
};

int main() {
    auto s = Solution();

    print("{}\n", s.numTrees(3)); //5
    print("{}\n", s.numTrees(1)); //1
}
