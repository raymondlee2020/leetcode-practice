class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = k, n = s.size(), maxcnt = 0;
        vector<int> cnt(26, 0);
        for (int l = 0, r = 0; r < n; ++r) {
            maxcnt = max(maxcnt, ++cnt[s[r] - 'A']);
            while (r - l + 1 - maxcnt > k) {
                --cnt[s[l++] - 'A'];
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};