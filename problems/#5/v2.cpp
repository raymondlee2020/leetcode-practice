class Solution {
public:
    string longestPalindrome(string s) {
        int n = 2 * s.size() + 1, resti = 1, reti = 1, diff;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            diff = resti + dp[resti] - i;
            if (diff > 0) dp[i] = min(dp[resti - (i - resti)], diff);
            while ((i + dp[i] < n - 1) && 
                   (i - dp[i] > 0) &&
                   ((i + dp[i] + 1) % 2 == 0 || s[re(i - dp[i] - 1)] == s[re(i + dp[i] + 1)])) ++dp[i];
            if (dp[i] > dp[reti]) reti = i;
            if (i + dp[i] > resti + dp[resti]) resti = i;
        }
        return s.substr(re(reti - dp[reti]), dp[reti]);
    }

    int re(int i) {
        return i / 2;
    }
};