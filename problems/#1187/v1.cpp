class Solution {
public:
    vector<vector<int>> dp;
    int n, m;

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        n = arr1.size(), m = arr2.size();
        dp = vector<vector<int>>(n, vector<int>(m + 1, -1));
        int ret = solve(0, -1, arr1, arr2);
        return ret == 1e9 ? -1 : ret;
    }

    int solve(int i, int prev, vector<int>& arr1, vector<int>& arr2) {
        if (i == n) {
            return 0;
        }
        int j = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (j == m && arr1[i] <= prev) {
            return dp[i][j] = 1e9;
        }
        int op = 1e9;
        int nop = 1e9;
        if (j != m) {
            op = 1 + solve(i + 1, arr2[j], arr1, arr2);
        }
        if (arr1[i] > prev) {
            nop = solve(i + 1, arr1[i], arr1, arr2);
        }
        return dp[i][j] = min(op, nop);
    }
};