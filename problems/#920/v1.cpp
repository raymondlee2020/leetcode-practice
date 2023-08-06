class Solution {
public:
    int MOD;

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));
        MOD = 1e9 + 7;
        return solve(dp, n, goal, k);
    }

    long long solve(vector<vector<int>>& dp, int n, int goal, int k) {
        if (n == 0 && goal == 0) {
            return 1;
        }
        if (n == 0 || goal == 0) {
            return 0;
        }
        if (dp[n][goal] != -1) {
            return dp[n][goal];
        }
        long long pick = solve(dp, n - 1, goal - 1, k) * n;
        long long notpick = solve(dp, n, goal - 1, k) * max(n - k, 0);
        return dp[n][goal] = (pick + notpick) % MOD;
    }
};