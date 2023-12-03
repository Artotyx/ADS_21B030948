#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    vector<int> children;
};

void dfs(int current, int parent, const vector<vector<int> >& adjList, vector<Node>& nodes) {
    for (size_t i = 0; i < adjList[current].size(); ++i) {
        int neighbor = adjList[current][i];
        if (neighbor != parent) {
            nodes[current].children.push_back(neighbor);
            dfs(neighbor, current, adjList, nodes);
        }
    }
}

int countBigFam(int current, const vector<Node>& nodes) {
    int count = 0;

    if (current == 0 || nodes[current].children.size() > 1) {
        count = 1;
    }

    for (size_t i = 0; i < nodes[current].children.size(); ++i) {
        int child = nodes[current].children[i];
        count += countBigFam(child, nodes);
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adjList(n);
    vector<Node> nodes(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adjList[x - 1].push_back(y - 1);
        adjList[y - 1].push_back(x - 1);
    }

    dfs(0, -1, adjList, nodes);

    int bigFamCount = countBigFam(0, nodes);

    cout << bigFamCount << endl;

    return 0;
}
