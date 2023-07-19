class Solution {
public:
    vector<int> dp;

    int numTrees(int n) {
        dp = vector<int>(n + 1, -1);
        dp[0] = 1;
        return solve(n);
    }

    int solve(int n) {
        if (dp[n] != -1) {
            return dp[n];
        }
        int ret = 0;
        for (int i = 1; i <= n; ++i) {
            ret += solve(i - 1) * solve(n - i);
        }
        return dp[n] = ret;
    }
};