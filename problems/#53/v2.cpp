class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int rdcr = nums[0];
        int ans = nums[0];
        for(unsigned int i = 1; i < nums.size(); i++)
        {
            rdcr = max(nums[i], rdcr + nums[i]);
            ans = max(ans, rdcr);
        }
        return ans;
    }
};