#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int a, const int b) {
            const int na = to_string(a).length();
            const int nb = to_string(b).length();

            return a * pow(10, nb) + b > b * pow(10, na) + a;
        });

        string response;

        for (auto elem: nums) {
            response += to_string(elem);
        }

        return response;
    }
};

int main() {
    Solution s;

    vector<int> a = {10, 2};
    cout << s.largestNumber(a) << endl; //210

    vector<int> b = {3, 30, 34, 5, 9};
    cout << s.largestNumber(b) << endl; //9534330

    return 0;
}
