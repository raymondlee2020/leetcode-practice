class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ret = n;
        for (int i = 0; i < n; ++i) ret ^= (i ^ nums[i]);
        return ret;
    }
};