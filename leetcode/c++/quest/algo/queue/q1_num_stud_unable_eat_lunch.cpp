#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
    }
};

int main() {
    auto s = Solution();
    vector<int> countStudents = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    cout << s.countStudents(countStudents, sandwiches) << '\n';


    vector<int> countStudents2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    cout << s.countStudents(countStudents2, sandwiches2) << '\n';
}
