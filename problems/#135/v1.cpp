class Solution {
public:
    int candy(vector<int>& ratings) {
        int ret = 1, n = ratings.size(), up = 1, down = 0, peak = 1;
        if (n == 0) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            if (ratings[i - 1] < ratings[i]) {
                ret += peak = ++up;
                down = 0;
            } else if (ratings[i - 1] > ratings[i]) {
                ++down;
                ret += down + (peak > down ? 0 : 1);
                up = 1;
            } else {
                peak = up  = 1, down = 0;
                ret += 1;
            }
        }
        return ret;
    }
};