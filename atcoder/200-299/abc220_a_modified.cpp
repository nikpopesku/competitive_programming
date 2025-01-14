#include <iostream>

int solution1(int &a, int &b, int &c) {
    int value = c;
    while (value <= a) {
        value += c;
    }

    int response = value <= b ? value : -1;

    return response;
}

long long solution2(int &a, int &b, int &c) {
    long long Y = b / c * c; // Y is a multiplt of C not exceeding B
    if (a <= Y) {
        return Y;
    } else {
        return -1;
    }
}

int main() {
    for (int a = 1; a <= 1000; a++) {
        for (int b = a; b <= 1000; b++) {
            for (int c = 1; c <= 1000; c++) {
                int s1 = solution1(a, b, c);
                long long s2 = solution2(a, b, c);
                if (s1 != s2) {
                    std::cout << s1 << ' ' << s2 << ' ' << a << ' ' << b << ' ' << c << std::endl;

                    return 0;
                }
            }
        }
    }
}