class Solution {
public:
    int n;
    vector<int> dp;

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        dp = vector<int>(target, -1);
        return solve(nums, target, 0);
    }

    int solve(vector<int>& nums, int target, int acc) {
        if (acc == target) {
            return 1;
        } else if (acc > target) {
            return 0;
        } else if (dp[acc] != -1) {
            return dp[acc];
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret += solve(nums, target, acc + nums[i]);
        }
        return dp[acc] = ret;
    }
};