#include <iostream>
#include <vector>
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
    int arrival, departure;
    std::cin >> n;
    std::priority_queue<Person, std::vector<Person>, ComparePerson> pq;

    for (int i = 0; i < n; ++i) {
        std::cin >> arrival >> departure;
        pq.emplace(arrival, departure);
    }

    while(!pq.empty()) {
        Person p = pq.pop();
        std::cout << p.arrival << ' ' << p.departure;
        pq.pop();
    }
}