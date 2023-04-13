class Solution {
public:
    int bound, n;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        bound = 0;
        for (const int num: nums) {
            bound += num;
        }
        if (bound % k != 0) {
            return false;
        }
        bound /= k;
        if (*max_element(nums.begin() , nums.end()) > bound) {
            return false;
        }
        sort(nums.begin() , nums.end(), greater<int>());
        vector<bool> used(n, false);
        return backtrack(k, nums, used, 0, 0);
    }

    bool backtrack(int rest, vector<int>& nums, vector<bool>& used, int curr, int pv) {
        if (rest == 1) {
            return true;
        }
        if (curr == bound) {
            return backtrack(rest - 1, nums, used, 0, 0);
        }
        for (int i = pv; i < n; ++i) {
            if (used[i] || curr + nums[i] > bound) {
                continue;
            }
            used[i] = true;
            if (backtrack(rest, nums, used, curr + nums[i], i)) {
                return true;
            }
            used[i] = false;
        }
        return false;
    }
};