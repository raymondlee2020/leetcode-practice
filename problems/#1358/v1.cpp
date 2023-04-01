class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        if (n < 3) {
            return 0;
        }
        unordered_map<char, int> last;
        last['a'] = -1;
        last['b'] = -1;
        last['c'] = -1;
        int ret = 0, l = 0, r = 1;
        last[s[l]] = l;
        last[s[r]] = r;
        while (r < n) {
            while (r < n && (last['a'] < l || last['b'] < l || last['c'] < l)) {
                last[s[r]] = ++r;
            }
            if (r < n) {
                ret += n - r;
            }
            ++l;
        }
        return ret;
    }
};