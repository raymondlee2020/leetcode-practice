class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxidx = 0;
        vector<int> ret;
        vector<vector<int>> dp(n, vector<int>(2));
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 0; --i) {
            dp[i][0] = 1, dp[i][1] = i;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] % nums[i] == 0 && dp[i][0] < dp[j][0] + 1) {
                    dp[i][0] = dp[j][0] + 1, dp[i][1] = j;
                    if (dp[i][0] > dp[maxidx][0]) {
                        maxidx = i;
                    }
                }
            }
        }
        while (dp[maxidx][1] != maxidx) {
            ret.push_back(nums[maxidx]);
            maxidx = dp[maxidx][1];
        }
        ret.push_back(nums[maxidx]);
        return ret;
    }
};