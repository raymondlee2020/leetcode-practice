class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        for (int num: arr) {
            m[num] = max(m[num], m[num - difference] + 1);
        }
        int ret = 0;
        for (auto [k, v]: m) {
            ret = max(ret, v);
        }
        return ret;
    }
};