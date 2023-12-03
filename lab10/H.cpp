#include <iostream>
#include <vector>

using namespace std;

void markIsland(vector<vector<char> >& grid, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
        return;
    }

    grid[row][col] = '0';

    markIsland(grid, row - 1, col); //up
    markIsland(grid, row + 1, col); 
    markIsland(grid, row, col - 1); //l
    markIsland(grid, row, col + 1); 
}

int numIslands(vector<vector<char> >& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1') {
                markIsland(grid, i, j);
                ++count;
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char> > grid(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int islands = numIslands(grid);

    cout << islands << endl;

    return 0;
}
