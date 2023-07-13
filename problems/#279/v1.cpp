class Solution {
public:
    int numSquares(int n) {
        int bound = sqrt(n);
        vector<vector<int>> dp(n + 1, vector<int>(bound + 1, -1));
        return solve(dp, n, bound);
    }

    int solve(vector<vector<int>>& dp, int num, int curr) {
        if (num < 0) {
            return INT_MAX;
        }
        if (num == 0) {
            return 0;
        }
        if (dp[num][curr] != -1) {
            return dp[num][curr];
        }
        int ret = INT_MAX, tmp;
        for (int i = curr; i > 0; --i) {
            ret = min(ret, solve(dp, num - pow(i, 2), i));
        }
        return dp[num][curr] = 1 + ret;
    }
};