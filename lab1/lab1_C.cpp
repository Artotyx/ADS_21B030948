#include <iostream>
#include <string>

using namespace std;

string processString(const string& str) {
    string result;
    for (char c : str) {
        if (c == '#') {
            if (!result.empty()) {
                result.pop_back();
            }
        } else {
            result.push_back(c);
        }
    }
    return result;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    string processedStr1 = processString(str1);
    string processedStr2 = processString(str2);

    if (processedStr1 == processedStr2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}