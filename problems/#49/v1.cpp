class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (auto str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            m[key].push_back(str);
        }
        vector<vector<string>> ret;
        for (auto [k, v]: m) {
            ret.push_back(v);
        }
        return ret;
    }
};