#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct Person {
    int arrival;
    int departure;

    Person(int arrival, int departure)
            : arrival(arrival), departure(departure) {
    }
};

struct ComparePerson {
    bool operator()(Person const &p1, Person const &p2) {
        return p1.departure > p2.departure;
    }
};

int main() {
    int n;
    int arrival, departure;
    int counter = 0, max_counter = 0;
    std::cin >> n;
    std::priority_queue<Person, std::vector<Person>, ComparePerson> pq;
    std::map<int, int> d;

    for (int i = 0; i < n; ++i) {
        std::cin >> arrival >> departure;
        pq.emplace(arrival, departure);
    }

    while (!pq.empty()) {
        Person p = pq.top();
        std::cout << p.arrival << ' ' << p.departure << std::endl;
        counter -= d[p.arrival];
        counter += 1;
        if (counter > max_counter) max_counter = counter;
        d[p.departure] += 1;
        pq.pop();
    }

    std::cout << max_counter << std::endl;
}