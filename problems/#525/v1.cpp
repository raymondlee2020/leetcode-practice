class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ret = 0, n = nums.size(), curr = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; ++i) {
            curr += nums[i] == 0 ? -1 : 1;
            if (m.find(curr) != m.end()) {
                ret = max(ret, i - m[curr]);
            } else {
                m[curr] = i;
            }
        }
        return ret;
    }
};