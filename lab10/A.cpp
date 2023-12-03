#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int row, col, minutes;
};

bool isValid(int row, int col, int m, int n) {
    return (row >= 0 && row < m && col >= 0 && col < n);
}

int kill(vector<vector<int> >& field) {
    int m = field.size();
    int n = field[0].size();

    vector<vector<bool> > visited(m, vector<bool>(n, false));
    queue<Cell> q;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 2) {
                Cell c;
                c.row = i;
                c.col = j;
                c.minutes = 0;
                q.push(c);
                visited[i][j] = true;
            }
        }
    }

    int minutes = 0;
    const pair<int, int> directions[] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        minutes = max(minutes, current.minutes);

        for (int d = 0; d < 4; ++d) {
            int newRow = current.row + directions[d].first;
            int newCol = current.col + directions[d].second;

            if (isValid(newRow, newCol, m, n) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;

                if (field[newRow][newCol] == 1) {
                    field[newRow][newCol] = 2;
                    Cell c;
                    c.row = newRow;
                    c.col = newCol;
                    c.minutes = current.minutes + 1;
                    q.push(c);
                } else if (field[newRow][newCol] == 0) {
                    Cell c;
                    c.row = newRow;
                    c.col = newCol;
                    c.minutes = current.minutes + 1;
                    q.push(c);
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 1 && !visited[i][j]) {
                return -1;
            }
        }
    }

    return minutes;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int> > field(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> field[i][j];
        }
    }

    int result = kill(field);

    cout << result << endl;

    return 0;
}
