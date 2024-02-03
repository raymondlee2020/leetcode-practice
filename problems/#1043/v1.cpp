class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int m = k + 1, n = arr.size(), currMax, l, r;
        vector<int> dp(m, 0);
        for (l = n - 1; l >= 0; --l) {
            currMax = 0;
            r = min(n, l + k);
            for (int i = l; i < r; ++i) {
                currMax = max(currMax, arr[i]);
                dp[l % m] = max(dp[l % m], dp[(i + 1) % m] + currMax * (i - l + 1));
            }
        }
        return dp[0];
    }
};