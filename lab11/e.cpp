#include <iostream>
#include <vector>
#include <set>

using namespace std;

int find(int n, vector<int>& parent);

void unionFind(int a, int b, vector<int>& parent, vector<int>& rank) {
  int rootA = find(a, parent);
  int rootB = find(b, parent);

  if (rootA == rootB) {
    return;
  }

  if (rank[rootA] < rank[rootB]) {
    parent[rootA] = rootB;
  } else if (rank[rootA] > rank[rootB]) {
    parent[rootB] = rootA;
  } else {
    parent[rootA] = rootB;
    rank[rootB]++;
  }
}

int find(int n, vector<int>& parent) {
  if (parent[n] == n) {
    return n;
  }
  return parent[n] = find(parent[n], parent);
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }

  vector<int> parent(n + 1);
  vector<int> rank(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }

  set<int> components;
  for (int i = 1; i <= n; ++i) {
    components.insert(i);
  }

  for (int i = n; i >= 1; --i) {
    for (int neighbor : graph[i]) {
      unionFind(i, neighbor, parent, rank);
      components.erase(find(neighbor, parent));
    }

    cout << components.size() << endl;
  }

  return 0;
}
