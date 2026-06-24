#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool previous_low = true;
        for (int i = 0; i < static_cast<int>(word.size()); ++i) {
            if (word[i] <= 'Z') {
                if (i == 0) previous_low = false;
                else if (previous_low == true) return false;
            } else {
                if (i > 1 && previous_low == false) {
                    return false;
                }
                previous_low = true;
            }
        }

        return true;
    }
};


int main() {
    auto s = Solution();
    cout << boolalpha << s.detectCapitalUse("USA") << '\n'; //true
    cout << boolalpha << s.detectCapitalUse("FlaG") << '\n'; //false
    cout << boolalpha << s.detectCapitalUse("FLaG") << '\n'; //false
    cout << boolalpha << s.detectCapitalUse("fLaG") << '\n'; //false
    cout << boolalpha << s.detectCapitalUse("FFFFFFFFFFFFFFFFFFFFf") << '\n'; //false
}
