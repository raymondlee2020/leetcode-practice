class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int total = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(total + 1, -1);
        vector<int> tmp(total + 1);
        dp[0] = 0;
        for (int rod : rods) {
            copy(dp.begin(), dp.end(), tmp.begin());
            for (int i = 0; i <= total - rod; ++i) {
                if (tmp[i] < 0) {
                    continue;
                }
                dp[i + rod] = max(dp[i + rod], tmp[i]);
                dp[abs(i - rod)] = max(dp[abs(i - rod)], tmp[i] + min(i, rod));
            }
        }
        return dp[0];
    }
};