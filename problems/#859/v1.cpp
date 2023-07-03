class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int n = s.size(), i = -1, j = -1;
        map<char, int> m;
        for (int idx = 0; idx < n; ++idx) {
            ++m[s[idx]];
            if (s[idx] == goal[idx]) {
                continue;
            }
            if (i != -1 && j != -1) {
                return false;
            } else if (i == -1) {
                i = idx;
            } else if (j == -1) {
                j = idx;
            }
        }
        if (i != -1 && j != -1 && s[i] == goal[j] && s[j] == goal[i]) {
            return true;
        }
        if (i == -1 && j == -1) {
            for (auto& [k, v]: m) {
                if (v > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};