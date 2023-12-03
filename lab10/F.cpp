#include <iostream>
#include <vector>

using namespace std;

void dfs(int vertex, const vector<vector<int> >& adjList, vector<bool>& visited) {
    visited[vertex] = true;

    for (size_t i = 0; i < adjList[vertex].size(); ++i) {
        int neighbor = adjList[vertex][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

bool inSameComponent(int s, int f, const vector<vector<int> >& adjList) {
    int n = adjList.size();
    vector<bool> visited(n, false);

    dfs(s - 1, adjList, visited);

    return visited[f - 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adjList(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adjList[x - 1].push_back(y - 1);
        adjList[y - 1].push_back(x - 1);
    }

    int s, f;
    cin >> s >> f;

    if (inSameComponent(s, f, adjList)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
