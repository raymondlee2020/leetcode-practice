class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxcnt = 0;
        unordered_map<int, int> cnt;
        for (const auto& num: nums) {
            if (++cnt[num] > maxcnt) {
                maxcnt = cnt[num];
            }
        }
        vector<vector<int>> ret(maxcnt);
        for (const auto& [k, v]: cnt) {
            for (int i = 0; i < v; ++i) {
                ret[i].push_back(k);
            }
        }
        return ret;
    }
};