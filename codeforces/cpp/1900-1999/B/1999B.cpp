#include <iostream>

int main() {
    int t, a1, a2, b1, b2;
    int su, sl;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> a1 >> a2 >> b1 >> b2;

        int response = 0;

        su = 0;
        sl = 0;
        if (a1 > b1) su += 1;
        if (a2 > b2) su += 1;
        if (a1 < b1) sl += 1;
        if (a2 < b2) sl += 1;
        if (su > sl) response += 1;

        su = 0;
        sl = 0;
        if (a1 > b2) su += 1;
        if (a2 > b1) su += 1;
        if (a1 < b2) sl += 1;
        if (a2 < b1) sl += 1;
        if (su > sl) response += 1;

        su = 0;
        sl = 0;
        if (a2 > b2) su += 1;
        if (a1 > b1) su += 1;
        if (a2 < b2) sl += 1;
        if (a1 < b1) sl += 1;
        if (su > sl) response += 1;


        su = 0;
        sl = 0;
        if (a2 > b1) su += 1;
        if (a1 > b2) su += 1;
        if (a2 < b1) sl += 1;
        if (a1 < b2) sl += 1;
        if (su > sl) response += 1;

        std::cout << response << std::endl;
    }
}
