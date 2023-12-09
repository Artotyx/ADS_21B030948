#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


int minCostConnectPoints(std::vector<int>& input) {
    int n = input.size();
    if (n <= 2) {
        return 0;
    }
    int cost = 0;
    std::vector<std::pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        points.push_back(std::make_pair(i, input[i]));
    }
    std::sort(points.begin(), points.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });
    std::vector<bool> connected(n, false);
    connected[points[0].first] = true;
    for (int i = 1; i < n; i++) {
        int min_cost = INT_MAX;
        int next_point = -1;
        for (int j = 0; j < n; j++) {
            if (!connected[points[j].first]) {
                int cost = points[0].second + points[j].second;
                if (cost < min_cost) {
                    min_cost = cost;
                    next_point = points[j].first;
                }
            }
        }
        cost += min_cost;
        connected[next_point] = true;
        points.erase(points.begin() + 0);
    }
    return cost;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> input(n);
    for (int i = 0; i < n; i++) {
        std::cin >> input[i];
    }
    std::cout << minCostConnectPoints(input) << std::endl;
    return 0;
}