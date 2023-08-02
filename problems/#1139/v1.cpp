class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int lo, ret = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> hor(m, vector<int>(n, 0)), ver(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    hor[i][j] = j == 0 ? 1 : hor[i][j - 1] + 1;
                    ver[i][j] = i == 0 ? 1 : ver[i - 1][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                lo = min(ver[i][j], hor[i][j]);
                while (lo > ret) {
                    if (ver[i][j - lo + 1] >= lo && hor[i - lo + 1][j] >= lo) {
                        ret = lo;
                    }
                    --lo;
                }
            }
        }
        return ret * ret;
    }
};