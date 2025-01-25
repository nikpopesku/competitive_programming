#include <iostream>
#include <vector>


int main() {
    int h, w;
    std::cin >> h >> w;
    std::string s;
    std::vector<std::string> vc;
    int top = h-1, right = 0, left = w - 1, down = 0;

    for (int i = 0; i < h; i++) {
        std::cin >> vc[i];

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '#') {
                if (i > top) top = i;
                if (i < down) down = i;
                if (j < left) left = j;
                if (j > right) right = j;
            }
        }
    }

    std::string response = "Yes";

    for (int i = top; i <= down; i++) {
        for (int j = left; j <= right; j++) {
            if (vc[i][j] == '.') {
                response = "No";
                break;
            }
        }
        if (response == "No") break;
    }

    std::cout << response << std::endl;
}