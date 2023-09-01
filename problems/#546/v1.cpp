class Solution {
public:
    vector<vector<vector<int>>> dp;

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(boxes, 0, n - 1, 0);
    }

    int solve(vector<int>& boxes, int i, int j, int k) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int ti = i, tk = k;
        for (; ti + 1 <= j && boxes[ti] == boxes[ti + 1]; ++ti, ++tk);
        int ret = (tk + 1) * (tk + 1) + solve(boxes, ti + 1, j, 0);
        for (int m = ti + 1; m <= j; ++m) {
            if (boxes[ti] == boxes[m]) {
                ret = max(ret, solve(boxes, ti + 1, m - 1, 0) + solve(boxes, m, j, tk + 1));
            }
        }
        return dp[i][j][k] = ret;
    }
};