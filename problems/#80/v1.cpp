class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l, r;
        for (l = 0, r = 0; r < nums.size(); ++r) {
            if (r > 1 && nums[r] == nums[l - 2]) {
                continue;
            }
            swap(nums[l++], nums[r]);
        }
        return l;
    }
};