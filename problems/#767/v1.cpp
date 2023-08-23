class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26);
        int mfchar = 0, n = s.size(), i;
        for (char c: s) {
            if (++cnt[c - 'a'] > cnt[mfchar]) {
                mfchar = c - 'a';
            }
        }
        if (2 * cnt[mfchar] - 1 > n) {
            return "";
        }
        i = 0;
        while (cnt[mfchar]-- > 0) {
            s[i] = mfchar + 'a';
            i += 2;
        }
        for (int c = 0; c < 26; ++c) {
            while (cnt[c]-- > 0) {
                if (i >= n) {
                    i = 1;
                }
                s[i] = c + 'a';
                i += 2;
            }
        }
        return s;
    }
};