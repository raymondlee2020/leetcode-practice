class Solution {
public:
    vector<int> DIR;

    int minimumEffortPath(vector<vector<int>>& heights) {
        DIR = {0, 1, 0, -1, 0};
        int m = heights.size(), n = heights[0].size(), nr, nc, tmp, ret;
        vector<int> curr;
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            if (dists[curr[1]][curr[2]] < curr[0]) {
                continue;
            }
            if (curr[1] == m - 1 && curr[2] == n - 1) {
                ret = curr[0];
                break;
            }
            for (int i = 0; i < 4; ++i) {
                nr = curr[1] + DIR[i], nc = curr[2] + DIR[i + 1];
                if (nr < 0 || nr == m || nc < 0 || nc == n) {
                    continue;
                }
                tmp = max(curr[0], abs(heights[curr[1]][curr[2]] - heights[nr][nc]));
                if (tmp < dists[nr][nc]) {
                    dists[nr][nc] = tmp;
                    pq.push({tmp, nr, nc});
                }
            }
        }
        return ret;
    }
};