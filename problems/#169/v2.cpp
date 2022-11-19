class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return recMajorityElement(nums, 0, nums.size() - 1);
    }
    
    int recMajorityElement(vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            return nums[lo];
        }
        
        int mid  = (lo + hi) / 2;
        int l = recMajorityElement(nums, lo, mid);
        int r = recMajorityElement(nums, (mid + 1), hi);
        if (l == r) {
            return l;
        }
        
        int lCnt = countInRange(nums, l, lo, hi);
        int rCnt = countInRange(nums, r, lo, hi);
        return lCnt > rCnt ? l : r;
    }
    
    int countInRange(vector<int>& nums, int ta, int lo, int hi) {
        int cnt = 0;
        for (const auto num: nums) {
            if (ta == num) {
                cnt++;
            }
        }
        return cnt;
    }
};