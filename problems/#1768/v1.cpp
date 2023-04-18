class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size(), idx = 0;
        string ret;
        while (idx < m && idx < n) {
            ret += word1[idx];
            ret += word2[idx];
            ++idx;
        }
        if (idx < m) {
            while (idx < m) {
                ret += word1[idx];
                ++idx;
            }
        }
        if (idx < n) {
            while (idx < n) {
                ret += word2[idx];
                ++idx;
            }
        }
        return ret;
    }
};