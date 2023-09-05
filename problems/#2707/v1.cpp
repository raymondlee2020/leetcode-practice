class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict;
        for (string word: dictionary) {
            dict.insert(word);
        }
        int currextra, minextra;
        string curr;
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            curr = "";
            minextra = n;
            for (int j = i; j < n; ++j) {
                curr.push_back(s[j]);
                currextra = (dict.count(curr) == 0 ? (j - i + 1) : 0) + dp[j + 1];
                minextra = min(minextra, currextra);
            }
            dp[i] = minextra;
        }
        return dp[0];
    }
};