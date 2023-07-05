class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), ret = 0, prev = 0, curr = 0;
        for (const auto& num: nums) {
            if (num == 0) {
                ret = max(ret, prev + curr);
                prev = curr;
                curr = 0;
            } else {
                ++curr;
            }
        }
        ret = max(ret, prev + curr);
        return ret == n ? n - 1 : ret;
    }
};