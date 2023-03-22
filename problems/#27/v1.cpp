class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l, r;
        for (l = 0, r = 0; r < nums.size(); ++r) {
            if (nums[r] == val) {
                continue;
            }
            swap(nums[l++], nums[r]);
        }
        return l;
    }
};