class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() == 0) {
            return ret;
        }
        int n = nums.size(), start = nums[0], curr = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] != curr + 1) {
                ret.push_back(start == curr ? to_string(start) : to_string(start) + "->" + to_string(curr));
                start = nums[i];
            }
            curr = nums[i];
        }
        ret.push_back(start == curr ? to_string(start) : to_string(start) + "->" + to_string(curr));
        return ret;
    }
};