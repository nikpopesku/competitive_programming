#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <map>

struct Person {
    int day;
    std::string type;

    Person(int day, std::string type)
            : day(day), type(std::move(type)) {
    }
};

struct ComparePerson {
    bool operator()(Person const &p1, Person const &p2) {
        if (p1.type == p2.type) return p1.day > p2.day;
        if (p1.day > p2.day) return true;
        if (p1.day == p2.day) return p1.type == "departure";

        return false;
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
        pq.emplace(arrival, "arrival");
        pq.emplace(departure, "departure");
    }

    while (!pq.empty()) {
        Person p = pq.top();
        std::cout << p.day << ' ' << p.type << std::endl;
        if (p.type == "arrival") ++counter;
        if (p.type == "departure") --counter;
        if (counter > max_counter) max_counter = counter;
        pq.pop();
    }

    std::cout << max_counter << std::endl;
}