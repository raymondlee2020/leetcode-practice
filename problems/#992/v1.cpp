class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        int ret = 0, n = nums.size(), l = 0, r;
        unordered_map<int, int> m;
        for (r = 0; r < n; ++r) {
            if (m[nums[r]]++ == 0) {
                --k;
            }
            while (k < 0) {
                if (--m[nums[l]] == 0) {
                    ++k;
                }
                ++l;
            }
            ret += (r - l + 1);
        }
        return ret;
    }
};