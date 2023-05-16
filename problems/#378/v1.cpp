class Solution {
public:
    int m, n;

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size();
        int l = matrix[0][0], r = matrix[m - 1][n - 1] + 1, mid, ret;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (countLessOrEqual(matrix, mid) >= k) {
                r = ret = mid;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    }

    int countLessOrEqual(vector<vector<int>>& matrix, int bound) {
        int ret = 0, j = n - 1;
        for (int i = 0; i < m; ++i) {
            while (j >= 0 && matrix[i][j] > bound) {
                --j;
            }
            ret += (j + 1);
        }
        return ret;
    }
};