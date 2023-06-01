class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), i, j, cost;
        queue<vector<int>> q;
        vector<int> curr;
        q.push({0, 0, 2});
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            i = curr[0], j = curr[1], cost = curr[2];
            if (i < 0 || i == n || j < 0 || j == n || grid[i][j] == 1) {
                continue;
            }
            if (grid[i][j] > 1 && grid[i][j] <= cost) {
                continue;
            }
            grid[i][j] = cost++;
            q.push({i - 1, j, cost});
            q.push({i, j - 1, cost});
            q.push({i + 1, j, cost});
            q.push({i, j + 1, cost});
            q.push({i - 1, j - 1, cost});
            q.push({i - 1, j + 1, cost});
            q.push({i + 1, j - 1, cost});
            q.push({i + 1, j + 1, cost});
        }
        return grid[n - 1][n - 1] < 2 ? -1 : (grid[n - 1][n - 1] - 1);
    }
};