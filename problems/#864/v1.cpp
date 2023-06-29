class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int moves = 0, allkeys = 0, s;
        queue<vector<int>> q;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << 6, false)));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0});
                    visited[i][j][0] = true;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    ++allkeys;
                }
            }
        }
        allkeys = (1 << allkeys) - 1;
        cout << allkeys;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> curr;
        int x, y, k;
        while (!q.empty()) {
            s = q.size();
            for (int i = 0; i < s; ++i) {
                curr = q.front();
                q.pop();
                if (curr[2] == allkeys) {
                    return moves;
                }
                for (const auto& dir: dirs) {
                    x = curr[0] + dir.first;
                    y = curr[1] + dir.second;
                    k = curr[2];
                    if (x < 0 || x == m || y < 0 || y == n || grid[x][y] == '#') {
                        continue;
                    }
                    if (grid[x][y] >= 'a' && grid[x][y] <= 'f') {
                        k = k | (1 << (grid[x][y] - 'a'));
                    } else if (grid[x][y] >= 'A' && grid[x][y] <= 'F' && !(k & 1 << (grid[x][y] - 'A'))) {
                        continue;
                    }
                    if (!visited[x][y][k]) {
                        visited[x][y][k] = true;
                        q.push({x, y, k});
                    }     
                }
            }
            ++moves;
        }
        return -1;
    }
};