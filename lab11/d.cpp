#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

 
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int minCost = INF;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] == 0) {
                int cost = 0;

                for (int u = 0; u < n; ++u) {
                    for (int v = 0; v < n; ++v) {
                        if (u != v) {
                            cost += min(graph[u][v], graph[u][i] + graph[j][v]);
                        }
                    }
                }

                minCost = min(minCost, cost);
            }
        }
    }

    cout << minCost << endl;

    return 0;
}