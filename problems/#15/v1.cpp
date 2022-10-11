class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        const int n = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] < (0 - nums[i])) {
                    j++;
                } else if (nums[j] + nums[k] > (0 - nums[i])) {
                    k--;
                } else {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    j++;
                    k--;
                }
            }
        }
        return ret;
    }
};