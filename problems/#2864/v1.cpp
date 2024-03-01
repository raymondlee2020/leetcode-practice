class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size() - 1, l = 0, r = 0;
        if (s[n] != '1') {
            for (; r < n; ++r) {
                if (s[r] == '1') {
                    swap(s[r], s[n]);
                    break;
                }
            }
        }
        for (; r < n; ++r) {
            if (s[r] == '1') swap(s[l++], s[r]);
        }
        return s;
    }
};