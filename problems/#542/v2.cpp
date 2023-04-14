class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int MAX_DIS = m + n;
        int top, left;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    continue;
                }
                top = (i - 1) >= 0 ? mat[i - 1][j] : MAX_DIS;
                left = (j - 1) >= 0 ? mat[i][j - 1] : MAX_DIS;
                mat[i][j] = min(top, left) + 1;
            }
        }
        int bottom, right;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j] == 0) {
                    continue;
                }
                bottom = (i + 1) == m ? MAX_DIS : mat[i + 1][j];
                right = (j + 1) == n ? MAX_DIS : mat[i][j + 1];
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};