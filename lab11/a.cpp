#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int u, v, w;
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool compare_edges(const Edge& a, const Edge& b) {
  return a.w < b.w;
}

int find(int u, int parent[]) {
  if (parent[u] == u) return u;
  return parent[u] = find(parent[u], parent);
}

void union_sets(int u, int v, int parent[], int size[]) {
  u = find(u, parent);
  v = find(v, parent);
  if (u == v) return;
  if (size[u] > size[v]) swap(u, v);
  parent[u] = v;
  size[v] += size[u];
}

int kruskal(vector<Edge>& edges, int n) {
  int parent[n], size[n];
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    size[i] = 1;
  }

  sort(edges.begin(), edges.end(), compare_edges);

  int mst_cost = 0;
  for (int i = 0; i < edges.size(); i++) {
    Edge edge = edges[i];
    int u = edge.u;
    int v = edge.v;
    int w = edge.w;
    if (find(u, parent) != find(v, parent)) {
      union_sets(u, v, parent, size);
      mst_cost += w;
    }
  }

  return mst_cost;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    for (int x = l; x < r; x++) {
      for (int y = x + 1; y <= r; y++) {
        edges.push_back(Edge(x - 1, y - 1, c));
      }
    }
  }

  int mst_cost = kruskal(edges, n);
  cout << mst_cost << endl;

  return 0;
}
