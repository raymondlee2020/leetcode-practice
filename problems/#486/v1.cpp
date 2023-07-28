class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(21, vector<int>(21, -1));
        return maxScore(dp, nums, sum, 0, nums.size() - 1) * 2 >= sum;
    }

    int maxScore(vector<vector<int>>& dp, vector<int>& nums, int sum, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        return dp[l][r] = sum - min(maxScore(dp, nums, sum - nums[l], l + 1, r), maxScore(dp, nums, sum - nums[r], l, r - 1));
    }
};