class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ret = -1, curr = 0;
        sort(nums.begin(), nums.end());
        for (const auto& num: nums) {
            if (curr > num) {
                ret = curr = curr + num;
            } else {
                curr += num;
            }
        }
        return ret;
    }
};