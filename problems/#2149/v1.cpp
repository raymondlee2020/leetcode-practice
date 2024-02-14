class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), even = 0, odd = 1;
        vector<int> ret(n);
        for (const auto& num: nums) {
            if (num > 0) {
                ret[even] = num;
                even += 2;
            } else {
                ret[odd] = num;
                odd += 2;
            }
        }
        return ret;
    }
};