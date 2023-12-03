#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool topologicalSort(int n, const vector<vector<int> >& requirements, vector<int>& indegree, vector<int>& result) {
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (size_t i = 0; i < requirements[current].size(); ++i) {
            int nextQuest = requirements[current][i];
            indegree[nextQuest]--;

            if (indegree[nextQuest] == 0) {
                q.push(nextQuest);
            }
        }
    }

    return result.size() == static_cast<size_t>(n);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > requirements(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int iQuest, jQuest;
        cin >> iQuest >> jQuest;
        requirements[iQuest].push_back(jQuest);
        indegree[jQuest]++;
    }

    vector<int> result;
    bool possible = topologicalSort(n, requirements, indegree, result);

    if (possible) {
        cout << "Possible" << endl;
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
