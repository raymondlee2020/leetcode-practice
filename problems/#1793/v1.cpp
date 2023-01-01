class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k;
        int j = k;
        int s = nums.size();
        int minVal = nums[k];
        int score = nums[k];
        while (i != 0 && j != (s - 1)) {
            if (nums[i - 1] > nums[j + 1]) {
                minVal = min(minVal, nums[--i]);
            } else {
                minVal = min(minVal, nums[++j]);
            }
            score = max(score, minVal * (j - i + 1));
        }
        if (i != 0) {
            while (i != 0) {
                minVal = min(minVal, nums[--i]);
                score = max(score, minVal * (j - i + 1));
            }
        }
        if (j != (s - 1)) {
            while (j != (s - 1)) {
                minVal = min(minVal, nums[++j]);
                score = max(score, minVal * (j - i + 1));
            }
        }
        return score;
    }
};