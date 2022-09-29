class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0;
        int max = nums[0];
        for(unsigned int i = 0; i < nums.size(); i++)
        {
            int cand = nums[i];
            if (i > 0 && prev > 0) {
                cand = prev + nums[i];
            }
            if (cand > max) {
                max = cand;
            }
            prev = cand;
        }
        return max;
    }
};