#include <iostream>
#include <deque>

using namespace std;

int main() {
  deque<int> d;
  char query;
  int number;

  while (cin >> query) {
    switch (query) {
      case '+':
        cin >> number;
        d.push_front(number);
        break;
      case '-':
        cin >> number;
        d.push_back(number);
        break;
      case '!':
        if (d.empty()) {
          cout << "error" << endl;
        } else {
          int sum = d.front() + d.back();
          cout << sum << endl;
        }
        break;
      case '*':
        if (d.empty()) {
          cout << "error" << endl;
        } else {
          int sum = d.front() + d.back();
          d.pop_front();
          d.pop_back();
          cout << sum << endl;
        }
        break;
    }
  }

  return 0;
}
