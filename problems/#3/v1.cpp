class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int slen = s.size();
        if (slen < 2) {
            return slen;
        }
        map<char, int> m;
        int l = 0, r = 0, maxlen = 0;
        m[s[0]] = 0;
        for (r = 1; r < slen; r++) {
            if (m.find(s[r]) != m.end() && m[s[r]] >= l) {
                maxlen = max(maxlen, r - l);
                l = m[s[r]] + 1;
            }
            m[s[r]] = r;
        }
        return maxlen == 0 ? slen : ((r - l) == 1 ? maxlen : max(maxlen, r - l));
    }
};

