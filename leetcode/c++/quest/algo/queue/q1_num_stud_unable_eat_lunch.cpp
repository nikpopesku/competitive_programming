#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        stack<int> sand;
        queue<int> q;
        int count_students_left = static_cast<int>(students.size());

        for (int i = static_cast<int>(sandwiches.size() - 1); i >= 0; --i) sand.push(sandwiches[i]);
        for (int i = 0; i < count_students_left; ++i) q.push(students[i]);


        while (!q.empty()) {

        }

        return count_students_left;
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
