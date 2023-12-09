#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
    int city1, city2, length;
    string asphaltType;
};

bool compareRoads(const Road& road1, const Road& road2) {
    return road1.length < road2.length;
}

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findSet(int u) {
        if (u != parent[u]) {
            parent[u] = findSet(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = findSet(u);
        int rootV = findSet(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootU] = rootV;
                rank[rootV]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    vector<Road> roads(m);
    for (int i = 0; i < m; ++i) {
        cin >> roads[i].asphaltType >> roads[i].city1 >> roads[i].city2 >> roads[i].length;
    }

    sort(roads.begin(), roads.end(), compareRoads);

    int totalCost = 0;
    DisjointSet ds(n);

    for (int i = 0; i < m; ++i) {
        int city1 = roads[i].city1;
        int city2 = roads[i].city2;

        if (ds.findSet(city1) != ds.findSet(city2)) {
            ds.unionSets(city1, city2);

            if (roads[i].asphaltType == "both") {
                totalCost += min(x, y) * roads[i].length;  
            } else if (roads[i].asphaltType == "big") {
                totalCost += x * roads[i].length;
            } else if (roads[i].asphaltType == "small") {
                totalCost += y * roads[i].length;
            }
        }
    }

    cout << totalCost << endl;

    return 0;
}