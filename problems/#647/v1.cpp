class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome(s, i, j)) ++ret;
            }
        }
        return ret;
    }

    bool isPalindrome(string s, int l, int r) {
        while (r - l > 1) {
            if (s[l++] != s[r--]) return false;
        }
        return s[l] == s[r];
    }
};