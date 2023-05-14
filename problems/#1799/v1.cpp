class Solution {
public:
    vector<int> dp;
    int n;

    int maxScore(vector<int>& nums) {
        n = nums.size();
        dp = vector<int>(1 << n, 0);
        return solve(nums, (1 << n) - 1, n / 2);
    }

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int solve(vector<int>& nums, int state, int last) {
        if (last == 0) {
            return 0;
        }
        if (dp[state] != 0) {
            return dp[state];
        }
        vector<int> cands;
        for (int i = 0; i < n; ++i) {
            if (state & (1 << i)) {
                cands.push_back(i);
            }
        }
        int ret = 0;
        for (int i = 0; i < cands.size(); ++i) {
            for (int j = i + 1; j < cands.size(); ++j) {
                ret = max(ret, gcd(nums[cands[i]], nums[cands[j]]) * last + solve(nums, state & ~(1 << cands[i]) & ~(1 << cands[j]), last - 1));
            }
        }
        return dp[state] = ret;
    }
};