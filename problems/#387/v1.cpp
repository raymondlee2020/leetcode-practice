class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (const auto& c: s) ++cnt[c - 'a'];
        for (int i = 0; i < n; ++i) {
            if (cnt[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};