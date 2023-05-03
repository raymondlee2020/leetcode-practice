class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, ret);
        return ret;
    }

    void backtrack(vector<int>& nums, int pv, vector<vector<int>>& ret) {
        if (pv == nums.size()) {
            ret.push_back(nums);
            return;
        }
        unordered_map<int, bool> used;
        for (int i = pv; i < nums.size(); ++i) {
            if (used[nums[i]]) {
                continue;
            }
            swap(nums[pv], nums[i]);
            backtrack(nums, pv + 1, ret);
            swap(nums[pv], nums[i]);
            used[nums[i]] = true;
        }
    }
};