class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        unordered_map<char, int> m;
        for (int i = 0; i < n; ++i) m[order[i]] = i;
        sort(s.begin(), s.end(), [&](const char& a, const char& b) { return m[a] < m[b]; });
        return s;
    }
};