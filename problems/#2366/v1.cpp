class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ret = 0;
        int n = nums.size(), prev = INT_MAX, curr;
        for (int i = n - 1; i >= 0; --i) {
            curr = nums[i];
            if (curr <= prev) {
                prev = curr;
                continue;
            }
            if (curr % prev == 0) {
                ret += (curr / prev - 1);
            } else {
                ret += (curr / prev);
                prev = (curr / (curr / prev + 1));
            }
        }
        return ret;
    }
};