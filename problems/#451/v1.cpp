class Solution {
public:
    string frequencySort(string s) {
        int i = 0, n = s.size();
        unordered_map<char, int> m;
        map<int, vector<char>> rm;
        for (const auto& c: s) ++m[c];
        for (const auto& [k, v]: m) rm[v].push_back(k);
        for (map<int, vector<char>>::reverse_iterator it = rm.rbegin(); it != rm.rend(); ++it) {
            int k = it->first;
            vector<char> v = it->second;
            for (const auto& c: v) {
                for (int j = 0; j < k; ++j, ++i) {
                    s[i] = c;
                }
            }
        }
        return s;
    }
};