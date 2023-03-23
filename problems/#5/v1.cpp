class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l, r, curr_len, longest_left = 0, longest_len = 1;
        for (int i = 0; i < n; ++i) {
            r = i;
            while (r < n && s[i] == s[r]) {
                ++r;
            }
            l = i - 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l, ++r;
            }
            curr_len = r - l - 1;
            if (curr_len > longest_len) {
                longest_left = l + 1;
                longest_len = curr_len;
            }
        }
        return s.substr(longest_left, longest_len);
    }
};