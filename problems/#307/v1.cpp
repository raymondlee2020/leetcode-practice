class NumArray {
public:
    int n, numsSum;
    vector<int> nums;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        numsSum = 0;
        for (int i = 0; i < n; ++i) {
            numsSum += nums[i];
        }
    }
    
    void update(int index, int val) {
        numsSum += val - nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int ret;
        if ((right - left) * 2 > n) {
            ret = numsSum;
            for (int i = 0; i < left; ++i) {
                ret -= nums[i];
            }
            for (int i = right + 1; i < n; ++i) {
                ret -= nums[i];
            }
        } else {
            ret = 0;
            for (int i = left; i <= right; ++i) {
                ret += nums[i];
            }
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */