#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortPLength(vector<vector<int> >& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, -1);

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (graph[current][neighbor] == 1 && dist[neighbor] == -1) {
                dist[neighbor] = dist[current] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist[end];
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    int result = shortPLength(graph, start - 1, end - 1);

    cout << result << endl;

    return 0;
}
