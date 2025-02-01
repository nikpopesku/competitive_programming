#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct Person {
    int day;
    std::string type;
    int ordinal_number;

    Person(int day, std::string type, int ordinal_number)
            : day(day), type(std::move(type)), ordinal_number(ordinal_number) {
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
    std::set<int> room_pool;
    std::vector<int> rooms(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> arrival >> departure;
        pq.emplace(arrival, "arrival", i + 1);
        pq.emplace(departure, "departure", i + 1);
        room_pool.insert(i + 1);
    }

    while (!pq.empty()) {
        Person p = pq.top();
        if (p.type == "arrival") {
            ++counter;
            rooms[p.ordinal_number - 1] = *room_pool.begin();
            room_pool.erase(room_pool.begin());
        }
        if (p.type == "departure") {
            --counter;
            room_pool.insert(rooms[p.ordinal_number] + 1);
        }
        if (counter > max_counter) max_counter = counter;
        pq.pop();
    }

    std::cout << max_counter << std::endl;
    for (int i = 0; i < rooms.size(); ++i) {
        std::cout << rooms[i];
        if (i < rooms.size()) std::cout << ' ';
        else std::cout << std::endl;
    }
    std::cout << std::endl;
}