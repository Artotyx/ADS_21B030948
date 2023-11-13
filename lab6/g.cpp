#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct NicknameChange {
    string oldNickname;
    string newNickname;
};

bool operator<(const NicknameChange& a, const NicknameChange& b) {
    return a.oldNickname < b.oldNickname;
}

int main() {
    int n;
    cin >> n;

    vector<NicknameChange> nicknameChanges;

    for (int i = 0; i < n; i++) {
        NicknameChange change;
        cin >> change.oldNickname >> change.newNickname;
        nicknameChanges.push_back(change);
    }

    sort(nicknameChanges.begin(), nicknameChanges.end());

    int uniqueUserCount = 1;

    for (int i = 1; i < n; i++) {
        if (nicknameChanges[i].oldNickname != nicknameChanges[i - 1].oldNickname) {
            uniqueUserCount++;
        }
    }

    cout << uniqueUserCount << endl;

    string currentUser = "";
    for (const NicknameChange& change : nicknameChanges) {
        if (change.oldNickname != currentUser) {
            cout << change.oldNickname << " " << change.newNickname << endl;
            currentUser = change.oldNickname;
        }
    }

    return 0;
}
