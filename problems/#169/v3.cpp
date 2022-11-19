class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0;
        int votes = 0;
        for (const auto num: nums) {
            if (votes == 0) {
                cand = num;
            }
            if (cand == num) {
                votes++;
            } else {
                votes--;
            }
        }
        return cand;
    }
};