class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i, j, n = mat.size(), ret = 0;
        for (i = 0, j = n - 1; i < n; ++i, --j) {
            ret += mat[i][i];
            ret += mat[i][j];
        }
        if (n % 2 == 1) {
            ret -= mat[n / 2][n / 2];
        }
        return ret;
    }
};