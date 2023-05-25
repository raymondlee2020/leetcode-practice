class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size(), l = -1, r = s.size();
        while (++l < n && !isalpha(s[l])) {}
        while (--r >= 0 && !isalpha(s[r])) {}
        while (l < r) {
            swap(s[l], s[r]);
            while (++l < n && !isalpha(s[l])) {}
            while (--r >= 0 && !isalpha(s[r])) {}
        }
        return s;
    }
};