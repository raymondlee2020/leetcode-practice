class Solution {
public:
    int n;

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        vector<int> tmp;
        int ret = INT_MAX;
        queueIsland(q, grid, getAnyIsland(grid));
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp[0] < 0 || tmp[0] == n || tmp[1] < 0 || tmp[1] == n) {
                continue;
            }
            if (tmp[2] >= cost[tmp[0]][tmp[1]]) {
                continue;
            }
            if (grid[tmp[0]][tmp[1]] == 1) {
                ret = min(ret, tmp[2] - 1);
                continue;
            }
            cost[tmp[0]][tmp[1]] = tmp[2]++;
            q.push({tmp[0] + 1, tmp[1], tmp[2]});
            q.push({tmp[0] - 1, tmp[1], tmp[2]});
            q.push({tmp[0], tmp[1] + 1, tmp[2]});
            q.push({tmp[0], tmp[1] - 1, tmp[2]});
        }
        return ret;
    }

    vector<int> getAnyIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<vector<int>> q;
        vector<int> ret, tmp;
        q.push({0, 0});
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            if (tmp[0] < 0 || tmp[0] == n || tmp[1] < 0 || tmp[1] == n || visited[tmp[0]][tmp[1]]) {
                continue;
            }
            if (grid[tmp[0]][tmp[1]] == 1) {
                ret = tmp;
                break;
            }
            visited[tmp[0]][tmp[1]] = true;
            q.push({tmp[0] + 1, tmp[1]});
            q.push({tmp[0] - 1, tmp[1]});
            q.push({tmp[0], tmp[1] + 1});
            q.push({tmp[0], tmp[1] - 1});
        }
        return ret;
    }

    void queueIsland(queue<vector<int>>& q, vector<vector<int>>& grid, vector<int> pos) {
        queue<vector<int>> tq;
        vector<int> tmp;
        tq.push(pos);
        while (!tq.empty()) {
            tmp = tq.front();
            tq.pop();
            if (tmp[0] < 0 || tmp[0] == n || tmp[1] < 0 || tmp[1] == n || grid[tmp[0]][tmp[1]] != 1) {
                continue;
            }
            grid[tmp[0]][tmp[1]] = 2;
            q.push({tmp[0], tmp[1], 0});
            tq.push({tmp[0] + 1, tmp[1]});
            tq.push({tmp[0] - 1, tmp[1]});
            tq.push({tmp[0], tmp[1] + 1});
            tq.push({tmp[0], tmp[1] - 1});
        }
    }
};