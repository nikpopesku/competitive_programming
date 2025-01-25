#include <iostream>
#include <vector>


int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector vc(h, std::vector<char>(w));
    int top = h - 1, right = 0, left = w - 1, down = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> vc[i][j];

            if (vc[i][j] == '#') {
                if (i < top) top = i;
                if (i > down) down = i;
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