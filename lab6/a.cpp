#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool albertSort(const char& a, const char& b) {
    if (isVowel(a) && isVowel(b)) {
        return a < b;
    } else if (!isVowel(a) && !isVowel(b)) {
        return a < b;
    } else {
        return isVowel(a);
    }
}

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    sort(s.begin(), s.end(), albertSort);

    cout << s << endl;

    return 0;
}
