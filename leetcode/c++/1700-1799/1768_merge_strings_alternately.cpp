#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        size_t i{0};
        size_t j{0};
        string response {};

        while (i < word1.length() or j < word2.length()) {
            if (i < word1.length()) {
                response += word1[i];
                i++;
            }

            if (j < word2.length()) {
                response += word2[j];
                j++;
            }
        }

        return response;
    }
};


int main() {
    auto s = Solution();
    cout << s.mergeAlternately("abc", "pqr") << endl;
}
