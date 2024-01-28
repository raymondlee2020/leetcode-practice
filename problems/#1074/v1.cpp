class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ret = 0, acc, m = matrix.size(), n = matrix[0].size();
        unordered_map<int, int> cnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                cnt = {{0, 1}};
                acc = 0;
                for (int k = 0; k < m; ++k) {
                    acc += matrix[k][j] - (i == 0 ? 0 : matrix[k][i - 1]);
                    ret += cnt.find(acc - target) == cnt.end() ? 0 : cnt[acc - target];
                    ++cnt[acc];
                }
            }
        }
        return ret;
    }
};