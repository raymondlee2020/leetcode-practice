class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0, tmp;
        for (const auto& num: nums) {
            tmp = max(prev + num, curr);
            prev = curr;
            curr = tmp;
        }
        return curr;
    }
};