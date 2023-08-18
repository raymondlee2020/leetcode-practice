class Solution {
public:
    int n;
    vector<vector<double>> dp;

    double largestSumOfAverages(vector<int>& nums, int k) {
        n = nums.size();
        dp = vector<vector<double>>(n, vector<double>(k + 1, -1));
        return solve(nums, 0, k);
    }

    double solve(vector<int>& nums, int idx, int k) {
        if (k == 0) {
            return 0.0;
        }
        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }
        if (k == 1) {
            return dp[idx][k] = (double) accumulate(nums.begin() + idx, nums.end(), 0) / (n - idx);
        }
        double ret = -DBL_MIN, tmp;
        for (int i = idx; i < n - k + 1; ++i) {
            tmp = ((double) accumulate(nums.begin() + idx, nums.begin() + (i + 1), 0) / (i - idx + 1)) + solve(nums, i + 1, k - 1);
            ret = max(ret, tmp);
        }
        return dp[idx][k] = ret;
    }
};