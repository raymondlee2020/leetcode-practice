class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ret(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                }
            }
        }
        vector<int> curr;
        int cost;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr[0] < 0 || curr[0] == m || curr[1] < 0 || curr[1] == n || ret[curr[0]][curr[1]] <= curr[2]) {
                continue;
            }
            ret[curr[0]][curr[1]] = curr[2]++;
            q.push({curr[0] + 1, curr[1], curr[2]});
            q.push({curr[0], curr[1] + 1, curr[2]});
            q.push({curr[0] - 1, curr[1], curr[2]});
            q.push({curr[0], curr[1] - 1, curr[2]});
        }
        return ret;
    }
};