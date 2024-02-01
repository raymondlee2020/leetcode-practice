class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size(), tmp;
        if (n % 3 != 0) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret(n / 3, vector<int>(3));
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            tmp = i / 3;
            ret[tmp][0] = nums[i];
            ret[tmp][1] = nums[i + 1];
            ret[tmp][2] = nums[i + 2];
        }
        return ret;
    }
};