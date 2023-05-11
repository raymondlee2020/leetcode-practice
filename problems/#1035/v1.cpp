class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left, top, leftop;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            left = leftop = 0;
            for (int j = 0; j < n; ++j) {
                top = dp[j];
                dp[j] = nums1[i] == nums2[j] ? (leftop + 1) : max(top, left);
                leftop = top;
                left = dp[j];
            }    
        }
        return dp[n - 1];
    }
};