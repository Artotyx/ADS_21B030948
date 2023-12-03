#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isAcyclic(int n, const vector<vector<int> >& adjList) {
    vector<int> indegree(n, 0);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        for (size_t j = 0; j < adjList[i].size(); ++j) {
            int neighbor = adjList[i][j];
            indegree[neighbor]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    int removedEdgeCount = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (size_t j = 0; j < adjList[current].size(); ++j) {
            int neighbor = adjList[current][j];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0 && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }

        removedEdgeCount++;
    }

    return removedEdgeCount == n;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adjList(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adjList[x - 1].push_back(y - 1);
    }

    if (isAcyclic(n, adjList)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
