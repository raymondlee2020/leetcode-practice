class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if (p.size() > s.size()) {
            return ret;
        }
        vector<int> whash(26, 0);
        vector<int> phash(26, 0);
        int l = 0, r = 0;
        for (; r < p.size(); r++) {
            whash[s[r] - 'a']++;
            phash[p[r] - 'a']++;
        }
        if (whash == phash) {
            ret.push_back(0);
        }
        l++;
        for (; r < s.size(); l++, r++) {
            whash[s[l - 1] - 'a']--;
            whash[s[r] - 'a']++;
            if (whash == phash) {
                ret.push_back(l);
            }
        }
        return ret;
    }
};