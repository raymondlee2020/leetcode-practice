class Solution {
public:
    int MOD;

    int numWays(int steps, int arrLen) {
        MOD = 1e9 + 7;
        vector<vector<int>> dp(steps / 2 + 1, vector<int>(steps + 1, -1));
        return solve(dp, arrLen, 0, steps);
    }

    int solve(vector<vector<int>>& dp, int arrLen, int idx, int steps) {
        if (idx < 0 || idx == arrLen || idx > steps) {
            return 0;
        }
        if (steps == 0) {
            return idx == 0 ? 1 : 0;
        }
        if (dp[idx][steps] != -1) {
            return dp[idx][steps];
        }
        int ret = solve(dp, arrLen, idx, steps - 1);
        ret = (ret + solve(dp, arrLen, idx + 1, steps - 1)) % MOD;
        ret = (ret + solve(dp, arrLen, idx - 1, steps - 1)) % MOD;
        return dp[idx][steps] = ret;
    }
};