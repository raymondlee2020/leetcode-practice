class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int tmpMinProd = nums[0];
        int tmpMaxProd = nums[0];
        for(unsigned int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == 0) {
                tmpMinProd = nums[i];
                tmpMaxProd = nums[i];
            } else {
                if (nums[i] < 0) {
                    swap(tmpMinProd, tmpMaxProd);
                }
                tmpMinProd = min(nums[i], tmpMinProd * nums[i]);
                tmpMaxProd = max(nums[i], tmpMaxProd * nums[i]);
            }
            maxProd = max(maxProd, tmpMaxProd);
        }
        return maxProd;
    }
};