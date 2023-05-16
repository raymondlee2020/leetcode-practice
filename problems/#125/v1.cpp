class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l = 0, r = s.size() - 1;
        while (l < n && !isalnum(s[l])) {
            ++l;
        }
        while (r >= 0 && !isalnum(s[r])) {
            --r;
        }
        while (l < r) {
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l, --r;
            while (l < n && !isalnum(s[l])) {
                ++l;
            }
            while (r >= 0 && !isalnum(s[r])) {
                --r;
            }
        }
        return true;
    }
};