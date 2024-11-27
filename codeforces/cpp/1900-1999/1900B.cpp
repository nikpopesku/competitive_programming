#include <iostream>
#include <vector>

using std::vector;

int main()
{
    int t;
    int n;
    std::string path;
    unsigned int count = 0;


    std::cin >> t;
    std::vector<unsigned int> response {};

    for (int i = 0; i < t; i++) {
        std::cin >> n;
        std::cin >> path;
        count = 0;

        for (int j = 0; j < n; j++) {
          if (path[j] == '@') {
            count++;
          } else if (path[j] == '*' and j > 0 and path[j-1] == '*') {
            break;
          }
        }

        response.push_back(count);
    }

    for (auto &i: response) {
      std::cout << i << std::endl;
    }


    return 0;
}