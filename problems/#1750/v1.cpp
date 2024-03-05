class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        char curr;
        while (l < r && s[l] == s[r]) {
            curr = s[l];
            while (l <= r && s[l] == curr) ++l;
            while (l <= r && s[r] == curr) --r;
        }
        return r - l + 1;
    }
};