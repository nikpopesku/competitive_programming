#include <print>
#include <vector>

using namespace std;

#define ull unsigned long long

class Solution {
public:
    int numTrees(int n) {
        vector<ull> fact(2 * n + 1, 1);

        for (ull i = 2; i < fact.size(); ++i) {
            fact[i] = i * fact[i - 1];
        }

        return fact[2 * n] / (n + 1) / fact[n] / fact[n];
    }
};

int main() {
    auto s = Solution();

    print("{}\n", s.numTrees(3)); //5
    print("{}\n", s.numTrees(1)); //1
    print("{}\n", s.numTrees(19)); //1
}
