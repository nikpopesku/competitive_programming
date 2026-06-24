#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool is_first = true;
        for (int i = 0; i < static_cast<int>(word.size()); ++i) {
            if (word[i] >= 'A') {
                if (i == 0) is_first = false;
                else if (is_first == false) return false;
            }
        }

        return true;
    }
};


int main() {
    auto s = Solution();
    cout << boolalpha << s.detectCapitalUse("USA") << '\n'; //true
    cout << boolalpha << s.detectCapitalUse("FlaG") << '\n'; //false
}
