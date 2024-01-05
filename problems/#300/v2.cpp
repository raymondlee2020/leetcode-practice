class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub = {nums[0]};
        for (int i = 1; i < n; ++i) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            }
            auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
            *it = nums[i];
        }
        return sub.size();
    }
};