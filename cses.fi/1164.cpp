#include <iostream>
#include <queue>

struct Person {

    int arrival;
    int departure;

    Person(int arrival, int departure)
            : arrival(arrival), departure(departure) {
    }
};

struct ComparePerson {
    bool operator()(Person const &p1, Person const &p2) {
        return p1.departure < p2.departure;
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arrival(n);
    std::vector<int> departure(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arrival[i] >> departure[i];
    }
}