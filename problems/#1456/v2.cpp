class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(), acc = 0, ret;
        vector<int> prefixVowelCnt(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                ++acc;
            }
            prefixVowelCnt[i] = acc;
        }
        ret = prefixVowelCnt[k - 1];
        for (int i = 1; i <= n - k; ++i) {
            ret = max(ret, prefixVowelCnt[i + k - 1] - prefixVowelCnt[i - 1]);
        }
        return ret;
    }
};