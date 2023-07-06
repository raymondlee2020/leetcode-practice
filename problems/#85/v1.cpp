class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ret = 0, cpscell, rpscell;
        vector<vector<int>> colps(m, vector<int>(n)) , rowps(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = n - 1, k = 0; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    rowps[i][j] = ++k;
                } else {
                    rowps[i][j] = k = 0;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = m - 1, k = 0; i >= 0; --i) {
                if (matrix[i][j] == '1') {
                    colps[i][j] = ++k;
                } else {
                    colps[i][j] = k = 0;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cpscell = colps[i][j], rpscell = rowps[i][j];
                for (int k = j + 1, o = j + rpscell; k < o; ++k) {
                    if (cpscell > colps[i][k]) {
                        ret = max(ret, cpscell * (k - j));
                        cpscell = colps[i][k];
                    }
                }
                ret = max(ret, cpscell * rpscell);
            }
        }
        return ret;
    }
};