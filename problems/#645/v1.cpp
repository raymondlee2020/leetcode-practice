class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 0), ret(2);
        for (int i = 0; i < n; ++i) {
            ++cnt[nums[i] - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) {
                ret[1] = i + 1;
            } else if (cnt[i] == 2) {
                ret[0] = i + 1;
            }
            
        }
        return ret;
    }
};