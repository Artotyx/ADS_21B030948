#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p1(n);
    vector<int> p2(m);

    for (int i = 0; i < n; i++) {
        cin >> p1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> p2[i];
    }

    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (p1[i] < p2[j]) {
            i++;
        } else if (p2[j] < p1[i]) {
            j++;
        } else {
            cout << p1[i] << " ";
            i++;
            j++;
        }
    }

    cout << endl;

    return 0;
}
