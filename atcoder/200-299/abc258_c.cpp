#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    int n, q, type, value;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    std::vector<char> vc(s.begin(), s.end());

    for (auto i = 1; i <= q; i++) {
        std::cin >> type >> value;

        if (type == 2) {
            std::cout << vc[value - 1] << std::endl;
        }

        if (type == 1) {
            value = value % n;
            std::rotate(vc.begin(),vc.end()-value,vc.end());
        }
    }
}