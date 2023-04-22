class Solution {
public:
    int s, MOD;
    vector<vector<vector<int>>> dp;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        MOD = 1000000007;
        s = group.size();
        dp = vector<vector<vector<int>>>(minProfit + 1, vector<vector<int>>(n + 1, vector<int>(s, -1)));
        return commit(0, n, minProfit, group, profit);
    }

    int commit(int curr, int maxPeople, int minProfit, vector<int>& group, vector<int>& profit) {
        if (maxPeople < 0) {
            return 0;
        }
        if (curr == s) {
            return minProfit > 0 ? 0 : 1;
        }
        minProfit = max(minProfit, 0);
        if (dp[minProfit][maxPeople][curr] != -1) {
            return dp[minProfit][maxPeople][curr];
        }
        dp[minProfit][maxPeople][curr] = (commit(curr + 1, maxPeople - group[curr], minProfit - profit[curr], group, profit) + commit(curr + 1, maxPeople, minProfit, group, profit)) % MOD;
        return dp[minProfit][maxPeople][curr];
    }
};