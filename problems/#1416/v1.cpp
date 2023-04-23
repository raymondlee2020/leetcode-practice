class Solution {
public:
    int MOD, n;
    vector<long> dp;

    int numberOfArrays(string s, int k) {
        MOD = 1000000007;
        n = s.size();
        dp = vector<long>(n, -1);
        return solve(0, s, k) % MOD;
    }

    int solve(int pv, string& s, long k) {
        if (pv == n) {
            return 1;
        }
        if (s[pv] == '0') {
            return 0;
        }
        if (dp[pv] != -1) {
            return dp[pv];
        }
        int ret = 0;
        long acc = 0;
        for (int i = pv; i < n; ++i) {
            acc = acc * 10 + digit(s[i]);
            if (acc > k) {
                break;
            }
            ret = (ret + solve(i + 1, s, k)) % MOD;
        }
        return dp[pv] = ret;
    }

    int digit(char c) {
        return c - '0';
    }
};