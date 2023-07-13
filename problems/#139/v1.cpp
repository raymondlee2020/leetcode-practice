class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        unordered_set wordset(wordDict.begin(), wordDict.end());
        int maxlen = 0;
        for (auto word: wordDict) {
            maxlen = max(maxlen, (int) word.size());
        }
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = max(0, i - maxlen); j < i; ++j) {
                if (dp[j] && wordset.find(s.substr(j, i - j)) != wordset.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};