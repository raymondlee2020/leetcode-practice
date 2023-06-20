class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n, -1);
        if (n < 2 * k + 1) {
            return ret;
        }
        long tmp = 0;
        for (int i = 0; i < 2 * k; ++i) {
            tmp += nums[i];
        }
        for (int i = 2 * k; i < n; ++i) {
            tmp += nums[i];
            ret[i - k] = tmp / (2 * k + 1);
            tmp -= nums[i - 2 * k];
        }
        return ret;
    }
};