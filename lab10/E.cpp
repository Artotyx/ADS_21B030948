#include <iostream>
#include <vector>

using namespace std;

bool canAddElements(const vector<vector<int> >& adjacencyMatrix, int a, int b, int c) {
    return (adjacencyMatrix[a][b] == 1 && adjacencyMatrix[b][c] == 1 && adjacencyMatrix[a][c] == 1);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int> > adjacencyMatrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        --a; --b; --c;  

        if (canAddElements(adjacencyMatrix, a, b, c)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
