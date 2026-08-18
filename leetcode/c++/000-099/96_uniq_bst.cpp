#include <print>
#include <vector>

using namespace std;

#define ull unsigned long long

class Solution {
public:
    int numTrees(int n) {
        vector<ull> fact(n + 1, 1);

        for (ull i = 2; i < fact.size(); ++i) {
            fact[i] = i * fact[i - 1];
        }

        ull response = 1;

        for (ull i = 1; i <= n; ++i) {
            response = response * (i + n) / i;
        }

        return static_cast<int>(response / (n + 1));
    }
};

int main() {
    auto s = Solution();

    print("{}\n", s.numTrees(3)); //5
    print("{}\n", s.numTrees(1)); //1
    print("{}\n", s.numTrees(19)); //1767263190
}
