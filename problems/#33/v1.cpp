class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lastIdx = nums.size() - 1;
        int minIdx = recFindMinIdx(nums, 0, lastIdx);
        return recSearch(nums, minIdx, (minIdx + lastIdx) % nums.size(), target);
    }
    
    int recFindMinIdx(vector<int>& nums, int start, int end) {
        if (nums[start] <= nums[end]) {
            return start;
        }
        if ((end - start) == 1) {
            return end;
        }
        int pv = (start + end) / 2;
        if (nums[pv] > nums[end]) {
            return recFindMinIdx(nums, pv, end);
        } else {
            return recFindMinIdx(nums, start, pv);
        }
    }
    
    int recSearch(vector<int>& nums, int start, int end, int target) {
        int pv = 0;
        if (end >= start) {
            pv = ((start + end) / 2) % nums.size();
        } else {
            pv = (((start + end + nums.size()) / 2) % nums.size());
        }
        if (nums[pv] == target) {
            return pv;
        }
        if (start == end) {
            return -1;
        }
        if (nums[pv] > target) {
            return recSearch(nums, start, pv,target);
        } else {
            return recSearch(nums, (pv + 1) % nums.size(), end, target);
        }
    }
};