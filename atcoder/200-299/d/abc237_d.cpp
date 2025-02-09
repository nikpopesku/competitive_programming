#include <iostream>
#include <list>


using namespace std;

int main() {
    int n;
    cin >> n;
    list a = {0};
    char s;
    auto it = a.begin();

    for (int i = 0; i < n; ++i) {
        cin >> s;


        if (s == 'L') {
            a.insert(it, i + 1);
            --it;
        }

        if (s == 'R') {
            a.insert(++it, i + 1);
            --it;
        }
    }

    for (it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin()) cout << ' ';
        cout << *it;
    }
}