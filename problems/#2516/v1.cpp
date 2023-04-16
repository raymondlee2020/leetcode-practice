class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> bound, curr;
        bound['a'] = 0;
        bound['b'] = 0;
        bound['c'] = 0;
        for (const auto c: s) {
            ++bound[c];
        }
        for (const auto [c, v]: bound) {
            if (v < k) {
                return -1;
            }
            bound[c] -= k;
        }
        int n = s.size(), intvl = 0, l = 0, r = 0;
        while (r < n) {
            ++curr[s[r]];
            ++r;
            while (curr['a'] > bound['a'] || curr['b'] > bound['b'] || curr['c'] > bound['c']) {
                --curr[s[l]];
                ++l;
            }
            intvl = max(intvl, (r - l));
        }
        return n - intvl;
    }
};