class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> m;
        for (const auto path: paths) {
            m[path[0]] = path[1];
        }
        string curr = paths[0][1];
        while (m.find(curr) != m.end()) {
            curr = m[curr];
        }
        return curr;
    }
};