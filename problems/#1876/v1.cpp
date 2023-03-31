class Solution {
public:
    int countGoodSubstrings(string s) {
        int ret = 0, l = 0, r = 2;
        for (; r < s.size(); ++l, ++r) {
            if ((r - l + 1) == 3 && s[l] != s[r] && s[l] != s[l + 1] && s[l + 1] != s[r]) {
                ++ret;
            }
        }
        return ret;
    }
};