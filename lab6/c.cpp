#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> points(N);
    vector<pair<int, int>> result;

    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int minDiff = INT_MAX;

    for (int i = 1; i < N; i++) {
        int diff = points[i] - points[i - 1];
        if (diff < minDiff) {
            minDiff = diff;
            result.clear();
            result.push_back({points[i - 1], points[i]});
        } else if (diff == minDiff) {
            result.push_back({points[i - 1], points[i]});
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i].first << " " << result[i].second;
        if (i < result.size() - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}
