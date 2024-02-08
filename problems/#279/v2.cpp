class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }

    int solve(vector<int>& dp, int num) {
        if (num < 0) {
            return INT_MAX;
        }
        if (num == 0) {
            return 0;
        }
        if (dp[num] != -1) {
            return dp[num];
        }
        int ret = INT_MAX, bound = sqrt(num);
        for (int i = bound; i > 0; --i) {
            ret = min(ret, solve(dp, num - pow(i, 2)));
        }
        return dp[num] = 1 + ret;
    }
};