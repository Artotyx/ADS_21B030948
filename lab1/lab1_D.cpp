#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool b(const string& s) {
    stack<char> stk;

    for (char c : s) {
        if (!stk.empty() && stk.top() == c) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }

    return stk.empty();
}

int main() {
    string s;
    cin >> s;

    if (b(s)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
