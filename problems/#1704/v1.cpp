class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), half = n / 2, cnt = 0;
        unordered_set<char> cs = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for (int i = 0; i < half; ++i) {
            if (cs.contains(s[i])) ++cnt;
        }
        for (int i = half; i < n; ++i) {
            if (cs.contains(s[i])) --cnt;
        }
        return cnt == 0;
    }
};