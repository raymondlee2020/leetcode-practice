class Solution {
public:
    map<int, int> dp;
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp.find(amount) != dp.end()) {
            return dp[amount];
        }
        int best = INT_MAX;
        int tmp;
        for (const int coin: coins) {
            tmp = coinChange(coins, amount - coin);
            if (tmp < 0) {
                continue;
            }
            best = min(best, tmp + 1);
        }
        dp[amount] = best == INT_MAX ? -1 : best;
        return dp[amount];
    }
};