#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    char letter;
    cin >> letter;

    vector<char> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    char balancedChar = 'z' + 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > letter) {
            balancedChar = arr[i];
            break;
        }
    }

    if (balancedChar > 'z') {
        cout << "No balanced char found" << endl;
    } else {
        cout << balancedChar << endl;
    }

    return 0;
}
