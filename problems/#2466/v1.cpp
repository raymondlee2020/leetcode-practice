class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int good_strs_end_with_zero_cnt, good_strs_end_with_one_cnt, idx, MOD = 1e9 + 7;
        for (int i = 1; i <= high; ++i) {
            idx = i - zero;
            good_strs_end_with_zero_cnt = idx < 0 ? 0 : dp[idx];
            idx = i - one;
            good_strs_end_with_one_cnt = idx < 0 ? 0 : dp[idx];
            dp[i] = (good_strs_end_with_zero_cnt + good_strs_end_with_one_cnt) % MOD;
        }
        int ret = 0;
        for (int i = low; i<= high; ++i) {
            ret = (ret + dp[i]) % MOD;
        }
        return ret;
    }
};