#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Query {
    int type, vertex;
};

void shortestDistances(const vector<vector<int> >& graph, const vector<int>& redVertices, vector<int>& distances) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    for (size_t i = 0; i < redVertices.size(); ++i) {
        q.push(redVertices[i]);
        visited[redVertices[i]] = true;
        distances[redVertices[i]] = 0;
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (size_t i = 0; i < graph[current].size(); ++i) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distances[neighbor] = distances[current] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int> > graph(n);
    vector<int> redVertices;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    vector<int> distances(n, INF);

    for (int i = 0; i < q; ++i) {
        Query query;
        cin >> query.type >> query.vertex;

        if (query.type == 1) {
            redVertices.push_back(query.vertex - 1);
            distances[query.vertex - 1] = 0;
        } else if (query.type == 2) {
            if (distances[query.vertex - 1] == INF) {
                cout << "-1" << endl;
            } else {
                cout << distances[query.vertex - 1] << endl;
            }
        }
    }

    return 0;
}
