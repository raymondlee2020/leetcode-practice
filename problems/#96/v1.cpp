class Solution {
public:
    vector<int> dp;

    int numTrees(int n) {
        dp = vector<int>(1 << n, -1);
        return solve((1 << n) - 1);
    }

    int solve(int nums) {
        if (nums == 0) {
            return 1;
        }
        if (dp[nums] != -1) {
            return dp[nums];
        }
        int ret = 0, p, l, r;
        for (int i = 1; i <= nums; i = i << 1) {
            p = nums & i;
            if (p == 0) {
                continue;
            }
            l = nums & (i - 1);
            r = nums - i - l;
            ret += solve(l) * solve(r);
        }
        return dp[nums] = ret;
    }
};