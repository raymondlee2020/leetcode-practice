class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), minlen = n + 1, l = 0, r;
        string ret = "";
        unordered_map<char, int> m;
        for (const auto& c: t) ++m[c];
        while (l < n && m.find(s[l]) == m.end()) ++l;
        r = l;
        while (r < n) {
            if (m.find(s[r]) != m.end()) {
                if (m[s[r]] <= 0 && l != r && s[l] == s[r]) {
                    ++l;
                    while (l < r) {
                        if (m.find(s[l]) == m.end()) {
                            ++l;
                            continue;
                        }
                        if (m[s[l]] >= 0) {
                            break;
                        } else {
                            ++m[s[l++]];
                        }
                    }
                } else {
                    --m[s[r]];
                }
            }
            if (isIncluded(m) && (r - l + 1) < minlen) {
                minlen = r - l + 1;
                ret = s.substr(l, minlen);
            }
            ++r;
        }
        return ret;
    }

    bool isIncluded(unordered_map<char, int>& m) {
        for (const auto& [k, v]: m) {
            if (v > 0) return false;
        }
        return true;
    }
};